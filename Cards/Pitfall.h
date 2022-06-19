
#ifndef EX4_Pitfall_H
#define EX4_Pitfall_H

#include <string>
#include <iostream>

#include "Player.h"
#include "Card.h"
#include "utilities.h"

class Pitfall : public Card{
public:
    /*
     * C'tor of Pitfall Card class
     *
     * @return
     *      A new instance of Pitfall Card.
    */
    Pitfall();

    /*
     * Handling the player's applyEncounter with the Pitfall card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Pitfall(const Pitfall&) = default;
    virtual ~Pitfall() = default;
    Pitfall& operator=(const Pitfall& other) = default;
};


#endif //EX4_Pitfall_H
