#ifndef EX4_Merchant_H
#define EX4_Merchant_H

#include <string>
#include <iostream>

#include "Player.h"
#include "Card.h"
#include "utilities.h"

class Merchant : public Card{
public:
    /*
     * C'tor of Merchant Card class
     *
     * @return
     *      A new instance of Merchant Card.
    */
    Merchant();

    /*
     * Handling the player's applyEncounter with the Merchant card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Merchant(const Merchant&) = default;
    virtual ~Merchant() = default;
    Merchant& operator=(const Merchant& other) = default;

private:
    enum class Action {Nothing = 0, HealthBoost, ForceBoost};
    static const int healCost = 5;
    static const int forceCost = 10;

    static Merchant::Action getUserAction();
};


#endif //EX4_Merchant_H
