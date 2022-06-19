#include <stdbool.h>
#include <string>

#include "Fighter.h"
#include "utilities.h"
#include "Player.h"

Fighter::Fighter(std::string name, std::string className) : Player(name), m_class(className) {}

int Fighter::getAttackStrength() const {
    return (getPlayerForce() * 2) + getLevel();
}

std::string Fighter::getClass() const {
    return this->m_class;
}

void Fighter::printClassPlayerDetails(std::ostream& os) const {
    printPlayerDetails(os, getPlayerName(), this->m_class, getLevel(), getPlayerForce(), getHp(), getCoins());
}