#ifndef EX2_Gang_H
#define EX2_Gang_H

#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <fstream>

#include "../Players/Player.h"
#include "Card.h"
#include "BattleCard.h"

class Gang : public Card{
public:
    /*
     * C'tor of Battle Card class
     *
     * @return
     *      A new instance of Battle Card.
    */
    Gang();

    /*
     * Handling the player's applyEncounter with the Gang card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;

    void addMonster(const std::string &monsterName);

    void parseFromStream(std::ifstream &fileStream);

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Gang(const Gang&) = default;
    ~Gang() = default;
    Gang& operator=(const Gang& other) = default;

private:
    std::vector<std::unique_ptr<BattleCard>> monsters;
};


#endif //EX2_Gang_H
