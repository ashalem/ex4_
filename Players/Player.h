
#ifndef EX4_Player_H
#define EX4_Player_H

#include <string>
#include <iostream>

#include "../Exception.h"


class Player {
public:
    /*
     * C'tor of Player class
     *
     * @param name - The name of the player.
     * @param hp - The max hp of player.
     * @param force - The starting force of player.
     * @return
     *      A new instance of Player.
    */
    Player(std::string name);
    
    /*
     * Levels up a player
     *
     * @return
     *      void
    */
    void levelUp();

    /*
     * Returns Levels of the player
     *
     * @return
     *      int, the player's level
    */
    int getLevel() const;

    /*
     * Increase player force
     *
     * @return
     *      void
    */
    void buff(const int buffPoints);

    /*
     * Decrease player force
     *
     * @return
     *      void
    */
    void debuff(const int debuffPoints);

    /*
     * Increase player current hp
     *
     * @return
     *      void
    */
    virtual void heal(const int healPoints);

    /*
     * Decrease player current hp
     *
     * @return
     *      void
    */
    void damage(const int damagePoints);

    /*
     * Decrease player current hp to zero
     *
     * @return
     *      void
    */
    void knockOut();

    /*
     * Checks if Player's life reached zero
     *
     * @return
     *      bool - true if player hp is zero
    */
    bool isKnockedOut() const;

    
    /*
     * Checks if Player already Won
     *
     * @return
     *      bool 
    */
    bool hasWon() const;

    /*
     * Checks if Player is playing
     *
     * @return
     *      bool 
    */
    bool isPlaying() const;

    /*
     * Increase player coins
     *
     * @return
     *      void
    */
    virtual void addCoins(const int coinsToAdd);

    /*
     * Decrease player coins
     *
     * @return
     *      bool - True if payment was made
    */
    bool pay(const int coinsToPay);

    /*
     * Returns player overall strength
     *
     * @return
     *      int - The player's strength
    */
    virtual int getAttackStrength() const;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Player(const Player&) = default;
    virtual ~Player() = default;
    Player& operator=(const Player& other) = default;

    /*
     *  outputStream (<<) operator printing instances of Player objects.
     *
     *  @return
     *          ostream object and prints the Player object in the right format.
     */
    friend std::ostream& operator<<(std::ostream& os, const Player& player);

    /*
     * @return
     *      string - the player's Class
    */
    virtual std::string getClass() const = 0;

    /*
     * @return
     *      int - the player's Name
    */
    std::string getName() const;

    /*
     * Gets the player info
     *
     * @return
     *      string - the player's info
    */
    virtual void printClassPlayerDetails(std::ostream& os) const = 0;

    /*
     * @return
     *      int - the player's current hp
    */
    int getHp() const;

    /*
     * @return
     *      int - the player's current coins
    */
    int getCoins() const;

    /*
     * @return
     *      int - the player's current force
    */
    int getForce() const;

    

private:

    /*
     * @return
     *      bool - if the inserted name is valid or not (according to the requirments). 
    */
    static bool isValidName(const std::string& name);

    static const int maxLevel = 10;
    static const int startingLevel = 1;
    static const int startingCoins = 10;
    static const int defaultMaxHp = 100;
    static const int defaultForce = 5;

    std::string m_name;
    int m_maxHp;
    int m_force;
    int m_HP;
    int m_level;
    int m_coins;
};


#endif //EX2_Player_H
