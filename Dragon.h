//
// Created by Daniel_Meents on 07/04/2022.
//
#ifndef EX4_Dragon_H
#define EX4_Dragon_H

#include <string>
#include <iostream>

#include "BattleCard.h"

class Dragon : public BattleCard{
public:
    /*
     * C'tor of Dragon class
     *
     * @return
     *      A new instance of Dragon.
    */
    Dragon();

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Dragon(const Dragon&) = default;
    virtual ~Dragon() = default;
    Dragon& operator=(const Dragon& other) = default;

private:
    void handleLoss(Player &player) const override;
};


#endif //EX4_Dragon_H
