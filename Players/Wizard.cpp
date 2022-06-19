#include <stdbool.h>
#include <string>

#include "Wizard.h"
#include "utilities.h"
#include "Player.h"

Wizard::Wizard(std::string name, std::string className) : Player(name), m_class(className) {}

void Wizard::heal(const int healPoints) {
    int doubleHealPoints = healPoints * 2;
    Player::heal(doubleHealPoints);
}

std::string Wizard::getClass() const {
    return this->m_class;
}

void Wizard::printClassPlayerDetails(std::ostream& os) const {
    printPlayerDetails(os, getPlayerName(), this->m_class, getLevel(), getPlayerForce(), getHp(), getCoins());
}