#ifndef EX4_Merchant_H
#define EX4_Merchant_H

#include <string>
#include <iostream>
#include <memory>

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
    enum class ActionEnum {Nothing = 0, HealthBoost, ForceBoost};
    class Action;
    class NoAction: public Action;
    class HealthPotion: public Action;
    class ForceBoost: public Action;

    static std::unique_ptr<Merchant::Action> getUserAction();
};

class Merchant::Action {
public:
    Action(int cost);
    virtual coid doBenefit(Player &player) const  = 0;

    virtual ~Action() = default;
    Action(const Action&) = default;
    operator=(const Action&) = default;

    int getCost() const;
private:
    int m_cost;
}

class Merchant::NoAction : public Merchant::Action {
public:
    HealthPotion();
    void doBenefit(Player &player) const override;

    virtual ~NoAction() = default;
    NoAction(const NoAction&) = default;
    operator=(const NoAction&) = default;
}

class Merchant::HealthPotion : public Merchant::Action {
public:
    HealthPotion();
    void doBenefit(Player &player) const override;

    virtual ~HealthPotion() = default;
    HealthPotion(const HealthPotion&) = default;
    operator=(const HealthPotion&) = default;
}

class Merchant::ForceBoost : public Merchant::Action {
public:
    ForceBoost();
    void doBenefit(Player &player) const override;

    virtual ~ForceBoost() = default;
    ForceBoost(const ForceBoost&) = default;
    operator=(const ForceBoost&) = default;
}


#endif //EX4_Merchant_H
