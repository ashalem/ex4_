#include <string>
#include <vector>
#include <memory>
#include <fstream>

#include "../utilities.h"
#include "../Players/Player.h"
#include "Card.h"
#include "BattleCard.h"
#include "Dragon.h"
#include "Vampire.h"
#include "Goblin.h"
#include "Gang.h"

Gang::Gang() : Card("Gang") {}

void Gang::applyEncounter(Player &player) const  {
    bool wasDefeated = false;
    for (const std::unique_ptr<BattleCard> &monster : monsters) {
        if (wasDefeated) {
            player.damage(monster->getDamage());
            monster->handleLoss(player);
            continue;
        }

        if (player.getAttackStrength() >= monster->getForce()) {
            player.addCoins(monster->getLoot());
        } else {
            wasDefeated = true;
            player.damage(monster->getDamage());
            monster->handleLoss(player);
            break;
        }
    }

    if (!wasDefeated) {
        player.levelUp();
    }
}

void Gang::addMonster(const std::string &monsterName) {
    if ("Dragon" == monsterName) {
        monsters.push_back(std::unique_ptr<Dragon>());
    } else if ("Vampire" == monsterName) {
        monsters.push_back(std::unique_ptr<Vampire>());
    } else if ("Goblin" == monsterName) {
        monsters.push_back(std::unique_ptr<Goblin>());
    } else {
        throw InvalidMonsterName(monsterName);
    }
}

void Gang::parseFromStream(std::ifstream &fileStream) {
    std::string monsterName;
    while (std::getline(fileStream, monsterName)) {
        addMonster(monsterName);
    }
}

