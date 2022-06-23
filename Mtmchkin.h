#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include <queue>
#include <memory>

#include "Cards/Card.h"
#include "Players/Player.h"
#include "Cards/Gang.h"

class Mtmchkin{

public:
    
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    Mtmchkin(const std::string fileName);
    
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

private:
    std::queue<std::shared_ptr<Card>> deck;
    std::vector<std::shared_ptr<Player>> players;
    std::vector<std::shared_ptr<Player>> wonPlayers;
    std::vector<std::shared_ptr<Player>> lostPlayers;
    int m_numRounds;
    static const int minDeckSize = 5;
    static const int minPlayersNum = 2;
    static const int maxPlayersNum = 6;

    void initializeDeckList(const std::string& fileName);
    void addNewCard(const std::string& cardName, std::ifstream &deckFile, int& lineNum);
    static std::shared_ptr<Gang> parseGangStream(std::ifstream &deckFile, int &lineNum);
    void initializePlayerQueue();
    int getNumOfPlayers() const;
    void parsePlayerDetails();
    static bool isValidName(const std::string& name);
    bool createClass(const std::string& playerClass, const std::string& name);
    void updatePlayersLists(std::shared_ptr<Player>& player);
    static bool readPlayerNameClass(std::string &playerName, std::string &playerClass);
};



#endif /* MTMCHKIN_H_ */
