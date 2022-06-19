#ifndef EX4_Rogue_H
#define EX4_Rogue_H

#include <string>
#include <iostream>

#include "Player.h"
#include "utilities.h"


class Rogue : public Player {
public:

    /*
     * C'tor of Rogue class
     *
     * @param name - The name of the Rogue.
     * @param hp - The max hp of Rogue.
     * @param force - The starting force of Rogue.
     * @return
     *      A new instance of Rogue.
    */
    Rogue(std::string name, std::string className);
    
    /*
     * Increase Rogue coins
     *
     * @return
     *      void
    */
    void addCoins(const int coinsToAdd) override;

    /*
     * @return
     *      string - the player's Class
    */
    virtual std::string getClass() const override;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Rogue(const Rogue&) = default;
    virtual ~Rogue() = default;
    Rogue& operator=(const Rogue& other) = default;

protected:

    /*
     * Gets the player info
     *
     * @return
     *      string - the player's info
    */
    virtual void printClassPlayerDetails(std::ostream& os) const override;

private:

    std::string m_class;
};

#endif //EX4_Rogue_H