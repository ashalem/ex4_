
#ifndef EX4_Barfight_H
#define EX4_Barfight_H

#include <string>
#include <iostream>

#include "Player.h"
#include "Card.h"
#include "utilities.h"

class Barfight : public Card{
public:
    /*
     * C'tor of Barfight Card class
     *
     * @return
     *      A new instance of Barfight Card.
    */
    Barfight();

    /*
     * Handling the player's applyEncounter with the Barfight card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Barfight(const Barfight&) = default;
    virtual ~Barfight() = default;
    Barfight& operator=(const Barfight& other) = default;
};


#endif //EX4_Barfight_H
