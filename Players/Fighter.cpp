#include <stdbool.h>
#include <string>

#include "Fighter.h"
#include "../utilities.h"
#include "Player.h"

Fighter::Fighter(std::string name) : Player(name), m_class("Fighter") {}

int Fighter::getAttackStrength() const {
    return (getForce() * 2) + getLevel();
}

std::string Fighter::getClass() const {
    return this->m_class;
}

void Fighter::printClassPlayerDetails(std::ostream& os) const {
    printPlayerDetails(os, getName(), this->m_class, getLevel(), getForce(), getHp(), getCoins());
}