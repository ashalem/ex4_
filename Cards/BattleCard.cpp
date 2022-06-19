#include <stdbool.h>
#include <string>

#include "utilities.h"
#include "Player.h"
#include "Card.h"
#include "BattleCard.h"

BattleCard::BattleCard(int force, int damage, int loot, const std::string &name) :
    Card(name), m_force(force), m_damage(damage), m_loot(loot) {}

void BattleCard::applyEncounter(Player &player) const  {
    bool hasWonBattle = (player.getAttackStrength() >= this->m_force);

    if (hasWonBattle) {
        printWinBattle(player.getName(), getName());
        player.levelUp();
        player.addCoins(getLoot());
    } else {
        printLossBattle(player.getName(), getName());
        player.damage(getDamage());
        handleLoss(player);
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