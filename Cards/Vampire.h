//
// Created by Daniel_Meents on 07/04/2022.
//
#ifndef EX4_Vampire_H
#define EX4_Vampire_H

#include <string>
#include <iostream>

#include "BattleCard.h"

class Vampire : public BattleCard{
public:
    /*
     * C'tor of Vampire class
     *
     * @return
     *      A new instance of Vampire.
    */
    Vampire();

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Vampire(const Vampire&) = default;
    ~Vampire() = default;
    Vampire& operator=(const Vampire& other) = default;
    void handleLoss(Player &player) const override;
};


#endif //EX4_Vampire_H
