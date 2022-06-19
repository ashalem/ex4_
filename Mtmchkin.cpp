#include <queue>
#include <fstream>
#include <string>
#include <memory>

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
#include "Mtmchkin.h"
#include "Exception.h"

void Mtmchkin::addNewCard(const std::string cardName, std::ifstream &deckFile) {
    std::string cardName;
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

Mtmchkin::Mtmchkin(const std::string fileName) {
    // Code for deck building in here!
    initializeDeckList(fileName);



    // Code for players in here!
}