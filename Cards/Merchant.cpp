#include <string>
#include <memory>

#include "../utilities.h"
#include "../Players/Player.h"
#include "Card.h"
#include "Merchant.h"

Merchant::Action::Action(int cost, Merchant::ActionEnum typeEnum) : m_cost(cost), m_typeEnum(typeEnum) {}

int Merchant::Action::getCost() const { 
    return this->m_cost;
}

Merchant::ActionEnum Merchant::Action::getTypeEnum() const { 
    return this->m_typeEnum;
}

Merchant::NoAction::NoAction() : Merchant::Action(0, Merchant::ActionEnum::Nothing) {}

void Merchant::NoAction::doBenefit(Player &player) const {}

Merchant::HealthPotion::HealthPotion() : Merchant::Action(5, Merchant::ActionEnum::HealthBoost) {}

void Merchant::HealthPotion::doBenefit(Player &player)  const {
    player.heal(1);
}

Merchant::ForceBoost::ForceBoost() : Merchant::Action(10, Merchant::ActionEnum::ForceBoost) {}

void Merchant::ForceBoost::doBenefit(Player &player)  const{
    player.buff(1);
}

Merchant::Merchant() : Card("Merchant") {}

std::unique_ptr<Merchant::Action> Merchant::getUserAction() {
    std::string userInput;
    std::getline(std::cin, userInput);

    int playerChoice;
    while (true) {
        try {
            playerChoice = std::stoi(userInput.c_str());
            //std::cout << "got player choice: " << userInput  << "translated: " << playerChoice << std::endl;
        } catch (std::invalid_argument& e) {
            //std::cout << "got error player choice: " << userInput << std::endl;
            printInvalidInput();
            std::getline(std::cin, userInput);
            continue;
        } catch (std::out_of_range& e) {
            //std::cout << "got error player choice: " << userInput << std::endl;
            printInvalidInput();
            std::getline(std::cin, userInput);
            continue;
        }

        switch (playerChoice) {
        case static_cast<int>(Merchant::ActionEnum::Nothing):
            return std::unique_ptr<Merchant::NoAction>(new Merchant::NoAction());
        case static_cast<int>(Merchant::ActionEnum::HealthBoost):
            return std::unique_ptr<Merchant::HealthPotion>(new Merchant::HealthPotion());
        case static_cast<int>(Merchant::ActionEnum::ForceBoost):
            return std::unique_ptr<Merchant::ForceBoost>(new Merchant::ForceBoost());
        default:
            printInvalidInput();
            std::getline(std::cin, userInput);
            continue;
        }
    }
}

void Merchant::applyEncounter(Player &player) const  {

    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());

    std::unique_ptr<Merchant::Action> merchantAction = getUserAction();

    if (player.pay(merchantAction->getCost())) {
        merchantAction->doBenefit(player);
        printMerchantSummary(std::cout,
                    player.getName(),
                    static_cast<int>(merchantAction->getTypeEnum()), 
                    merchantAction->getCost());
    } else {
        printMerchantInsufficientCoins(std::cout);
        printMerchantSummary(std::cout,
                    player.getName(),
                    static_cast<int>(merchantAction->getTypeEnum()), 
                    0);
    }

}
