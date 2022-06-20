#ifndef EX4_Card_H
#define EX4_Card_H

#include <string>
#include <iostream>

#include "../Players/Player.h"
#include "../Exception.h"

class Card {
public:
    /*
     * C'tor of Card class
     *
     * @return
     *      A new instance of Card.
    */
    Card(std::string name);


    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(Player& player) const = 0;


    /*
     * Gets the card info
     *
     * @return
     *      string - the card's info
    */
    virtual void printDetails(std::ostream& os) const;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Card(const Card&) = default;
    virtual ~Card() = default;
    Card& operator=(const Card& other) = default;

    /*
     *  outputStream (<<) operator printing instances of Card objects.
     *
     *  @return
     *          ostream object and prints the Card object in the right format.
     */
    friend std::ostream& operator<<(std::ostream& os, const Card& card);

    std::string getName() const;

private:

    /*
     * @return
     *      bool - if the inserted name is valid or not (according to the requirments). 
    */
    static bool isValidName(const std::string& name);

    std::string m_name;
};


#endif //EX4_Card_H
