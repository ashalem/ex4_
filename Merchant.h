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
    class NoAction;
    class HealthPotion;
    class ForceBoost;
    static std::unique_ptr<Merchant::Action> getUserAction();
};

class Merchant::Action {
public:
    Action(int cost, Merchant::ActionEnum typeEnum);
    virtual void doBenefit(Player &player) const  = 0;
    Merchant::ActionEnum getTypeEnum() const;

    virtual ~Action() = default;
    Action(const Action&) = default;
    Action& operator=(const Action&) = default;

    int getCost() const;
private:
    int m_cost;
    Merchant::ActionEnum m_typeEnum;
};

class Merchant::NoAction : public Merchant::Action {
public:
    NoAction();
    void doBenefit(Player &player) const override;

    ~NoAction() = default;
    NoAction(const NoAction&) = default;
    NoAction& operator=(const NoAction&) = default;
};

class Merchant::HealthPotion : public Merchant::Action {
public:
    HealthPotion();
    void doBenefit(Player &player) const override;

     ~HealthPotion() = default;
    HealthPotion(const HealthPotion&) = default;
    HealthPotion& operator=(const HealthPotion&) = default;
};

class Merchant::ForceBoost : public Merchant::Action {
public:
    ForceBoost();
    void doBenefit(Player &player) const override;

    ~ForceBoost() = default;
    ForceBoost(const ForceBoost&) = default;
    ForceBoost&  operator=(const ForceBoost&) = default;
};


#endif //EX4_Merchant_H
