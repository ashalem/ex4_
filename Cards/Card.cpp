#include <string>
#include <iostream>

#include "../utilities.h"
#include "../Players/Player.h"
#include "Card.h"
#include "../Exception.h"


bool Card::isValidName(const std::string& name){
    
    int name_length = name.length();
    if(name_length > 15){
        return 0;
    }

    for (int chr = 0; chr < name_length; chr++){
        if(!std::isalpha(name[chr])){
            return 0;
        }
    }

    return 1;
}

Card::Card(std::string name) : m_name(name) {

    if(!(isValidName(name))){
            throw InvalidNameInput("Invalid name input for the card.");
        }
}

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
