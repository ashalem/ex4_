#ifndef EX4_Wizard_H
#define EX4_Wizard_H

#include <string>
#include <iostream>

#include "Player.h"


class Wizard : public Player {
public:

    /*
     * C'tor of Wizard class
     *
     * @param name - The name of the Wizard.
     * @param hp - The max hp of Wizard.
     * @param force - The starting force of Wizard.
     * @return
     *      A new instance of Wizard.
    */
    Wizard(std::string name, std::string className);
    
    /*
     * Increase Wizard current hp
     *
     * @return
     *      void
    */
    void heal(const int healPoints) override;

    /*
     * @return
     *      string - the player's Class
    */
    virtual std::string getClass() const override;

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Wizard(const Wizard&) = default;
    virtual ~Wizard() = default;
    Wizard& operator=(const Wizard& other) = default;

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

#endif //EX4_Wizard_H