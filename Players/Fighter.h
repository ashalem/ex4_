#ifndef EX4_Fighter_H
#define EX4_Fighter_H

#include <string>
#include <iostream>

#include "Player.h"


class Fighter : public Player {
public:

    /*
     * C'tor of Fighter class
     *
     * @param name - The name of the Fighter.
     * @param hp - The max hp of Fighter.
     * @param force - The starting force of Fighter.
     * @return
     *      A new instance of Fighter.
    */
    Fighter(std::string name, std::string className);
    
    /*
     * Returns player overall strength
     *
     * @return
     *      int - The Fighter's strength
    */
    int getAttackStrength() const override;

    /*
     * @return
     *      string - the player's Class
    */
    virtual std::string getClass() const override;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Fighter(const Fighter&) = default;
    virtual ~Fighter() = default;
    Fighter& operator=(const Fighter& other) = default;

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

#endif //EX4_Fighter_H