#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include <queue>
#include <memory>

#include "Cards/Card.h"
#include "Players/Player.h"

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
    int m_numRounds;

    void initializeDeckList(const std::string fileName);
    void addNewCard(const std::string cardName, std::ifstream &deckFile);
    void initializePlayerQueue();
    int getNumOfPlayers() const;
    void getPlayerNameAndClass();
    static bool isValidName(const std::string& name);
    bool didCreateClass(const std::string& playerClass, const std::string& name);
};



#endif /* MTMCHKIN_H_ */
