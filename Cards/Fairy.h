
#ifndef EX4_Fairy_H
#define EX4_Fairy_H

#include <string>
#include <iostream>

#include "Player.h"
#include "Card.h"
#include "utilities.h"

class Fairy : public Card{
public:
    /*
     * C'tor of Fairy Card class
     *
     * @return
     *      A new instance of Fairy Card.
    */
    Fairy();

    /*
     * Handling the player's applyEncounter with the Fairy card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Fairy(const Fairy&) = default;
    virtual ~Fairy() = default;
    Fairy& operator=(const Fairy& other) = default;
};


#endif //EX4_Fairy_H
