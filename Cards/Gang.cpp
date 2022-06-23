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

void Gang::applyMonsterLoss(BattleCard &monster, Player& player) const {
    printLossBattle(player.getName(), monster.getName());
    player.damage(monster.getDamage());
    monster.handleLoss(player);
}

void Gang::applyEncounter(Player &player) const  {
    bool wasDefeated = false;
    for (const std::unique_ptr<BattleCard> &monster : monsters) {
        if (wasDefeated) {
            applyMonsterLoss(*monster, player);
            continue;
        }

        if (player.getAttackStrength() >= monster->getForce()) {
            player.addCoins(monster->getLoot());
        } else {
            wasDefeated = true;
            applyMonsterLoss(*monster, player);
        }
    }

    if (!wasDefeated) {
        printWinBattle(player.getName(), getName());
        player.levelUp();
    }
}

void Gang::addMonster(const std::string &monsterName) {
    if ("Dragon" == monsterName) {
        monsters.push_back(std::unique_ptr<Dragon>(new Dragon()));
    } else if ("Vampire" == monsterName) {
        monsters.push_back(std::unique_ptr<Vampire>(new Vampire()));
    } else if ("Goblin" == monsterName) {
        monsters.push_back(std::unique_ptr<Goblin>(new Goblin()));
    } else {
        throw InvalidMonsterName(monsterName);
    }
}


