#ifndef EX2_BattleCard_H
#define EX2_BattleCard_H

#include <string>
#include <iostream>

#include "../Players/Player.h"
#include "Card.h"

class BattleCard : public Card{
public:
    /*
     * C'tor of Battle Card class
     *
     * @return
     *      A new instance of Battle Card.
    */
    BattleCard(int force, int damage, int loot, const std::string &name);

    /*
     * Handling the player's applyEncounter with the battle card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    void applyEncounter(Player& player) const override;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    BattleCard(const BattleCard&) = default;
    ~BattleCard() = default;
    BattleCard& operator=(const BattleCard& other) = default;

    void printDetails(std::ostream& os) const override;

    int getForce() const;
    int getDamage() const;
    int getLoot() const;

private:
    int m_force;
    int m_damage;
    int m_loot;

    virtual void handleLoss(Player &player) const = 0;
};


#endif //EX2_BattleCard_H
