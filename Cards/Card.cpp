#include <string>
#include <iostream>

#include "utilities.h"
#include "Player.h"
#include "Card.h"

Card::Card(std::string name) : m_name(name) {}

std::string Card::getName() const {
    return this->m_name;
}

void Card::printDetails(std::ostream& os) const{
    printCardDetails(os, getName());
}

std::ostream& operator<<(std::ostream& os, const Card& card) {
    card.printDetails(os);
    printEndOfCardDetails(os);
    return os;
}
