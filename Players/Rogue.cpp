#include <stdbool.h>
#include <string>

#include "Rogue.h"
#include "utilities.h"
#include "Player.h"

Rogue::Rogue(std::string name, std::string className) : Player(name), m_class(className) {};

void Rogue::addCoins(const int coinsToAdd) {
    int doubleCoins = coinsToAdd * 2;
    Player::addCoins(doubleCoins);
}

std::string Rogue::getClass() const {
    return this->m_class;
}

void Rogue::printClassPlayerDetails(std::ostream& os) const {
    printPlayerDetails(os, getPlayerName(), this->m_class, getLevel(), getPlayerForce(), getHp(), getCoins());
}