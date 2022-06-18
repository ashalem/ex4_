//
// Created by Daniel_Meents on 07/04/2022.
//
#ifndef EX4_Goblin_H
#define EX4_Goblin_H

#include <string>
#include <iostream>

#include "BattleCard.h"

class Goblin : public BattleCard{
public:
    /*
     * C'tor of Goblin class
     *
     * @return
     *      A new instance of Goblin.
    */
    Goblin();

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Goblin(const Goblin&) = default;
    virtual ~Goblin() = default;
    Goblin& operator=(const Goblin& other) = default;

private:
    void handleLoss(Player &player) const override {};
};


#endif //EX4_Goblin_H
