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

    throw DeckFileFormatError(lineNum);
}

void Mtmchkin::addNewCard(const std::string& cardName, std::ifstream &deckFile, int &lineNum) {
    if ("Dragon" == cardName) {
        m_deck.push(std::shared_ptr<Dragon>(new Dragon()));
    } else if ("Vampire" == cardName) {
        m_deck.push(std::shared_ptr<Vampire>(new Vampire()));
    } else if ("Goblin" == cardName) {
        m_deck.push(std::shared_ptr<Goblin>(new Goblin()));
    } else if ("Merchant" == cardName) {
        m_deck.push(std::shared_ptr<Merchant>(new Merchant()));
    } else if ("Treasure" == cardName) {
        m_deck.push(std::shared_ptr<Treasure>(new Treasure()));
    } else if ("Pitfall" == cardName) {
        m_deck.push(std::shared_ptr<Pitfall>(new Pitfall()));
    } else if ("Fairy" == cardName) {
        m_deck.push(std::shared_ptr<Fairy>(new Fairy()));
    } else if ("Barfight" == cardName) {
        m_deck.push(std::shared_ptr<Barfight>(new Barfight()));
    } else if ("Gang" == cardName) {
        m_deck.push(parseGangStream(deckFile, lineNum));
    } else {
        throw DeckFileFormatError(lineNum);
    }
}

void Mtmchkin::initializeDeckList(const std::string& fileName) {
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

    if (m_deck.size() < minDeckSize) {
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

        if(playerChoice >= minPlayersNum && playerChoice <= maxPlayersNum){
            break;
        } 
        printInvalidTeamSize();
    }
    return playerChoice;
}

bool Mtmchkin::isValidName(const std::string& name) {

    int name_length = name.length();
    if(name_length > Player::maxNameLen){
        return false;
    }

    for (int i = 0; i < name_length; i++){
        if(!std::isalpha(name[i])){
            return false;
        }
    }

    return true;
}
bool Mtmchkin::createClass(const std::string& playerClass, const std::string& name) {
    if(playerClass == "Fighter") {
        std::shared_ptr<Fighter> fighter(new Fighter(name));
        m_players.push_back(fighter);
        return true;
    }else if(playerClass == "Rogue") {
        std::shared_ptr<Rogue> rogue(new Rogue(name));
        m_players.push_back(rogue);
        return true;
    }else if(playerClass == "Wizard") {
        std::shared_ptr<Wizard> wizard(new Wizard(name));
        m_players.push_back(wizard);
        return true;
    }

    return false;
}

bool Mtmchkin::readPlayerNameClass(std::string &playerName, std::string &playerClass) {
    std::size_t firstSpace;
    std::string playerInput;
    std::getline(std::cin, playerInput);
    firstSpace = playerInput.find(' ');
    if (firstSpace == std::string::npos) {
        return false;
    }
    playerName = playerInput.substr(0, firstSpace);
    playerClass = playerInput.substr(firstSpace + 1);
    return true;
}

void Mtmchkin::parsePlayerDetails() {
    std::string playerName, playerClass;
    printInsertPlayerMessage();
    while(true) {
        if (!readPlayerNameClass(playerName, playerClass)) {
            printInvalidName();
            continue;
        }
        
        if(!isValidName(playerName)){
            printInvalidName();
            continue;
        }

        if(!createClass(playerClass, playerName)){
            printInvalidClass();
            continue;
        }

        break;
    }
}

void Mtmchkin::initializePlayerQueue() {
    int numPlayers = getNumOfPlayers();
    for (int i = 0; i < numPlayers; i++) {
        parsePlayerDetails();
    }

}

void Mtmchkin::updatePlayersLists(std::shared_ptr<Player>& player) {
    if (player->isKnockedOut()) {
        this->m_lostPlayers.push_back(player);
    } else if (player->hasWon()) {
        this->m_wonPlayers.push_back(player);
    }
}

void Mtmchkin::playRound() {
    this->m_numRounds++;
    printRoundStartMessage(this->m_numRounds);
    for (std::shared_ptr<Player>& currentPlayer: m_players) {
        if(!currentPlayer->isPlaying()){
            continue;
        }
        printTurnStartMessage(currentPlayer->getName());
        std::shared_ptr<Card> currentCard = m_deck.front();
        currentCard->applyEncounter(*currentPlayer);
        this->updatePlayersLists(currentPlayer);
        m_deck.pop();
        m_deck.push(currentCard);
    }
    if (isGameOver()) {
        printGameEndMessage();
    }
}

void Mtmchkin::printLeaderBoard() const {
    printLeaderBoardStartMessage();
    int ranking = 1;
    for (const std::shared_ptr<Player>& wonPlayer : this->m_wonPlayers) {
        printPlayerLeaderBoard(ranking, *wonPlayer);
        ranking++;
    }

    for (const std::shared_ptr<Player>& currentPlayer : this->m_players) {
        if (currentPlayer->isPlaying()) {
            printPlayerLeaderBoard(ranking, *currentPlayer);
            ranking++;
        }
    }

    for (std::vector<std::shared_ptr<Player>>::const_reverse_iterator lostPlayer = this->m_lostPlayers.rbegin();
           lostPlayer != this->m_lostPlayers.rend();  ++lostPlayer) {
        printPlayerLeaderBoard(ranking, *(*lostPlayer));
        ranking++;
    }
}

bool Mtmchkin::isGameOver() const {
    return (this->m_wonPlayers.size() + this->m_lostPlayers.size()) == this->m_players.size();
}

int Mtmchkin::getNumberOfRounds() const {
    return this->m_numRounds;
}
 