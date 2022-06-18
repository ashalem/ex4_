#include <stdbool.h>
#include <string>

#include "utilities.h"
#include "Player.h"
#include "Card.h"
#include "BattleCard.h"

BattleCard::BattleCard(int force, int damage, int loot, const std::string &name) :
    Card(name), m_force(force), m_damage(damage), m_loot(loot), {}

void BattleCard::applyEncounter(Player &player) const  {
    bool hasWonBattle = (player.getAttackStrength() >= this->force); // TODO: Change

    if (hasWonBattle) {
        printWinBattle(player.name, getName());
        player.levelUp();
        player.addCoins(getLoot());
    } else {
        printLossBattle(player.name, getName());
        player.damage(getDamage())
        this->handleLoss(player);
    }
}

void BattleCard::printDetails(std::ostream& os) const {
    printCardDetails(os, getName());
    printMonsterDetails(os, getForce(), getDamage(), getLoot(), getName() == "Dragon");
}

int BattleCard::getLoot() const {
    return this->m_loot;
}

int BattleCard::getForce() const {
    return this->m_force;
}

int BattleCard::getDamage() const {
    return this->m_damage;
}