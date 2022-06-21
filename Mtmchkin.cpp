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

std::shared_ptr<Gang> Mtmchkin::parseGangStream(std::ifstream &deckFile, int &lineNum) {
    std::shared_ptr<Gang> aGang(new Gang());

    std::string monsterName;
    while (std::getline(deckFile, monsterName)) {
        lineNum++;
        if ("EndGang" == monsterName){
            return aGang;
        };
        aGang->addMonster(monsterName);
    }

    ////std::cout << "In gang error" << std::endl;
    throw DeckFileFormatError(lineNum);
}

void Mtmchkin::addNewCard(const std::string cardName, std::ifstream &deckFile, int &lineNum) {
    if ("Dragon" == cardName) {
        deck.push(std::shared_ptr<Dragon>(new Dragon()));
    } else if ("Vampire" == cardName) {
        deck.push(std::shared_ptr<Vampire>(new Vampire()));
    } else if ("Goblin" == cardName) {
        ////std::cout << "gg" << std::endl;
        deck.push(std::shared_ptr<Goblin>(new Goblin()));
    } else if ("Merchant" == cardName) {
        deck.push(std::shared_ptr<Merchant>(new Merchant()));
    } else if ("Treasure" == cardName) {
        deck.push(std::shared_ptr<Treasure>(new Treasure()));
    } else if ("Pitfall" == cardName) {
        deck.push(std::shared_ptr<Pitfall>(new Pitfall()));
    } else if ("Fairy" == cardName) {
        deck.push(std::shared_ptr<Fairy>(new Fairy()));
    } else if ("Barfight" == cardName) {
        deck.push(std::shared_ptr<Barfight>(new Barfight()));
    } else if ("Gang" == cardName) {
        deck.push(parseGangStream(deckFile, lineNum));
    } else {
        ////std::cout << "card name " << cardName << std::endl;
        throw DeckFileFormatError(lineNum);
    }
}

void Mtmchkin::initializeDeckList(const std::string fileName) {
    std::ifstream deckFile(fileName);
    if (!deckFile) {
        throw DeckFileNotFound();
    }

    std::string cardName;
    int lineNum = 1;
    while (std::getline(deckFile, cardName)) {
        addNewCard(cardName, deckFile, lineNum);
        lineNum++;
    }

    if (deck.size() < minDeckSize) {
        throw DeckFileInvalidSize();
    }
}

Mtmchkin::Mtmchkin(const std::string fileName) : m_numRounds(0) {
    printStartGameMessage();
    initializeDeckList(fileName);
    initializePlayerQueue();
}

int Mtmchkin::getNumOfPlayers() const{
     int playerChoice;
     std::string userInput;
     while(true) {
        printEnterTeamSizeMessage();
        std::getline(std::cin, userInput);
        try {
            playerChoice = std::stoi(userInput.c_str());
        } catch (std::invalid_argument& e) {
            printInvalidTeamSize();
            continue;
        } catch (std::out_of_range& e) {
            printInvalidTeamSize();
            continue;
        }
        if(playerChoice >= 2 && playerChoice <= 6){
            break;
        } 
        printInvalidTeamSize();
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
    bool validInput = false;
    std::size_t firstSpace;
    std::string playerName, playerClass, playerInput;
    printInsertPlayerMessage();
    while(!validInput) {
        std::getline(std::cin, playerInput);
        firstSpace = playerInput.find(' ');
        if (firstSpace == std::string::npos) {
            printInvalidName();
            continue;
        }
        playerName = playerInput.substr(0, firstSpace);
        //std::cout << "received: " << playerInput << " to: " << playerName;
        if(!isValidName(playerName)){
            //std::cout << "invalid name" << std::endl;
            printInvalidName();
            continue;
        }
        playerClass = playerInput.substr(firstSpace+1);
        //std::cout << "class: " << playerClass << std::endl;
        if(!didCreateClass(playerClass, playerName)){
            //std::cout << "invalid class" << std::endl;
            printInvalidClass();
            continue;
        }
        validInput = true;
    }
}

void Mtmchkin::initializePlayerQueue() {
    int numPlayers = getNumOfPlayers();
    for (int i = 1; i <= numPlayers; i++) {
        getPlayerNameAndClass();
    }

}

void Mtmchkin::updatePlayersLists(std::shared_ptr<Player>& player) {
    if (player->isKnockedOut()) {
        this->lostPlayers.push_back(player);
    } else if (player->hasWon()) {
        this->wonPlayers.push_back(player);
    }
}

void Mtmchkin::playRound() {
    this->m_numRounds++;
    printRoundStartMessage(this->m_numRounds);
    ////std::cout << "Players num: " << this->players.size() << "Deck size: " << this->deck.size() << std::endl;
    for (std::shared_ptr<Player>& currentPlayer: players) {
        ////std::cout << "in player: " << currentPlayer->getName();
        if(!currentPlayer->isPlaying()){
            continue;
        }
        printTurnStartMessage(currentPlayer->getName());
        std::shared_ptr<Card> currentCard = deck.front();
        currentCard->applyEncounter(*currentPlayer);
        this->updatePlayersLists(currentPlayer);
        deck.pop();
        deck.push(currentCard);
    }
    if (isGameOver()) {
        printGameEndMessage();
    }
}

void Mtmchkin::printLeaderBoard() const {
    printLeaderBoardStartMessage();
    int ranking = 1;
    for (const std::shared_ptr<Player>& wonPlayer : this->wonPlayers) {
        printPlayerLeaderBoard(ranking, *wonPlayer);
        ranking++;
    }

    for (const std::shared_ptr<Player>& currentPlayer : this->players) {
        if (currentPlayer->isPlaying()) {
            printPlayerLeaderBoard(ranking, *currentPlayer);
            ranking++;
        }
    }

    for (std::vector<std::shared_ptr<Player>>::const_reverse_iterator lostPlayer = this->lostPlayers.rbegin();
           lostPlayer != this->lostPlayers.rend();  ++lostPlayer) {
        printPlayerLeaderBoard(ranking, *(*lostPlayer));
        ranking++;
    }
}

bool Mtmchkin::isGameOver() const {
    return (this->wonPlayers.size() + this->lostPlayers.size()) == this->players.size();
}

int Mtmchkin::getNumberOfRounds() const {
    return this->m_numRounds;
}
 