#include <queue>
#include <fstream>
#include <string>
#include <memory>
#include <iostream>

#include "Cards/Card.h"
#include "Cards/Dragon.h"
#include "Cards/Vampire.h"
#include "Cards/Goblin.h"
#include "Cards/Merchant.h"
#include "Cards/Treasure.h"
#include "Cards/Pitfall.h"
#include "Cards/Fairy.h"
#include "Cards/Barfight.h"
#include "Cards/Gang.h"
#include "Players/Player.h"
#include "Players/Fighter.h"
#include "Players/Wizard.h"
#include "Players/Rogue.h"
#include "Mtmchkin.h"
#include "Exception.h"
#include "utilities.h"

void Mtmchkin::addNewCard(const std::string cardName, std::ifstream &deckFile) {
    if ("Dragon" == cardName) {
        deck.push(std::shared_ptr<Dragon>());
    } else if ("Vampire" == cardName) {
        deck.push(std::shared_ptr<Vampire>());
    } else if ("Goblin" == cardName) {
        deck.push(std::shared_ptr<Goblin>());
    } else if ("Merchant" == cardName) {
        deck.push(std::shared_ptr<Merchant>());
    } else if ("Treasure" == cardName) {
        deck.push(std::shared_ptr<Treasure>());
    } else if ("Pitfall" == cardName) {
        deck.push(std::shared_ptr<Pitfall>());
    } else if ("Fairy" == cardName) {
        deck.push(std::shared_ptr<Fairy>());
    } else if ("Barfight" == cardName) {
        deck.push(std::shared_ptr<Barfight>());
    } else if ("Gang" == cardName) {
        std::shared_ptr<Gang> aGang;
        aGang->parseFromStream(deckFile);
        deck.push(aGang);
    } else {
        throw InvalidCardName(cardName);
    }
}

void Mtmchkin::initializeDeckList(const std::string fileName) {
    std::ifstream deckFile(fileName);
    if (!deckFile) {
        std::cerr << "Received invalid deck file: " << fileName << std::endl;
        throw InvalidDeckFile(fileName);
    }

    std::string cardName;
    while (std::getline(deckFile, cardName)) {
        addNewCard(cardName, deckFile);
    }

}

Mtmchkin::Mtmchkin(const std::string fileName) : m_numRounds(0) {
    // Code for deck building in here!
    initializeDeckList(fileName);
    initializePlayerQueue();


    // Code for players in here!
}

int Mtmchkin::getNumOfPlayers() const{
     int playerChoice, validInput = 0;
     std::string userInput;
     while(!validInput) {
        printEnterTeamSizeMessage();
        std::getline(std::cin, userInput);
        try {
            playerChoice = std::stoi(userInput.c_str());
        } catch (std::invalid_argument) {
            std::cout << "Invalid team input! Please enter an integer." << std::endl;
            continue;
        }
        if(playerChoice >= 2 && playerChoice <= 6){
            validInput = 1;
        } 
        else {
            printInvalidTeamSize();
        }
    }
    return playerChoice;
}

bool Mtmchkin::isValidName(const std::string& name){

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
bool Mtmchkin::didCreateClass(const std::string& playerClass, const std::string& name) {
    if(playerClass == "Fighter") {
        std::shared_ptr<Fighter> fighter(new Fighter(name));
        players.push_back(fighter);
        return 1;
    }else if(playerClass == "Rogue") {
        std::shared_ptr<Rogue> rogue(new Rogue(name));
        players.push_back(rogue);
        return 1;
    }else if(playerClass == "Wizard") {
        std::shared_ptr<Wizard> wizard(new Wizard(name));
        players.push_back(wizard);
        return 1;
    }

    return 0;
}
void Mtmchkin::getPlayerNameAndClass() {
    int validInput = 0;
    std::string playerName, playerClass;
    while(!validInput) {
        printInsertPlayerMessage();
        std::cin >> playerName;
        if(!isValidName(playerName)){
            printInvalidName();
            continue;
        }
        std::cin >> playerClass;
        if(!didCreateClass(playerClass, playerName)){
            printInvalidClass();
            continue;
        }
        validInput = 1;
    }
}

void Mtmchkin::initializePlayerQueue() {
    printStartGameMessage();
    int numPlayers = getNumOfPlayers();
    printInsertPlayerMessage();
    for (int i = 1; i <= numPlayers; i++) {
        getPlayerNameAndClass();
    }

}

void Mtmchkin::playRound() {
    this->m_numRounds++;
    printRoundStartMessage(this->m_numRounds);
    for (std::shared_ptr<Player>& current_player: players) {
        if(current_player->getLevel() == 10 || current_player->isKnockedOut()){
            continue;
        }
        std::shared_ptr<Card> current_card = deck.front();
        current_card->applyEncounter(*current_player);
        deck.pop();
        deck.push(current_card);
    }
}

int Mtmchkin::getNumberOfRounds() const {
    return this->m_numRounds;
}