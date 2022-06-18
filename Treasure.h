//
// Created by Daniel_Meents on 07/04/2022.
//
#ifndef EX4_Treasure_H
#define EX4_Treasure_H

#include <string>
#include <iostream>

#include "Player.h"
#include "Card.h"
#include "utilities.h"

class Treasure : public Card{
public:
    /*
     * C'tor of Treasure Card class
     *
     * @return
     *      A new instance of Treasure Card.
    */
    Treasure();

    /*
     * Handling the player's applyEncounter with the treasure card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Treasure(const Treasure&) = default;
    virtual ~Treasure() = default;
    Treasure& operator=(const Treasure& other) = default;
};


#endif //EX4_Treasure_H
