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
    std::queue<std::shared_ptr<Card>> m_deck;
    std::vector<std::shared_ptr<Player>> m_players;
    std::vector<std::shared_ptr<Player>> m_wonPlayers;
    std::vector<std::shared_ptr<Player>> m_lostPlayers;
    int m_numRounds;
    static const int minDeckSize = 5;
    static const int minPlayersNum = 2;
    static const int maxPlayersNum = 6;


    void initializeDeckList(const std::string& fileName);
    void addNewCard(const std::string& cardName, std::ifstream &deckFile, int& lineNum);
    static std::shared_ptr<Gang> parseGangStream(std::ifstream &deckFile, int &lineNum);

    /*
    * Initialize the Players in a queue of the the Mtmchkin class and gets the team size.
    *
    * @return
    *      void 
    */
    void initializePlayerQueue();

    /*
    * Gets the number of Players from the user (only number between 2-6).
    *
    * @return
    *      int - the number of players in the game. 
    */
    int getNumOfPlayers() const;

    /*
    * Gets from the user the Player's name and class (and checks if it is valid).
    *
    * @return
    *      void 
    */
    void parsePlayerDetails();

    /*
    * Checks if the inserted name is valid, accoring to the requirments.
    *
    * @return
    *      bool - if the name if valid or not. 
    */
    static bool isValidName(const std::string& name);

    /*
    * Checks the Validity of class name inserted and if so, creates a new instance of the class.
    *
    * @return
    *      bool - if the class name inserted was valid and an object was created. 
    */
    bool createClass(const std::string& playerClass, const std::string& name);

    /*
    * Checks from all players which ones won / died and puts them in the relevent list.
    *
    * @return
    *      void 
    */
    void updatePlayersLists(std::shared_ptr<Player>& player);

    /*
    * Checks the Validity of the player's name and class name inserted.
    *
    * @return
    *      bool - if the names inserted are valid. 
    */
    static bool readPlayerNameClass(std::string &playerName, std::string &playerClass);
};



#endif /* MTMCHKIN_H_ */
