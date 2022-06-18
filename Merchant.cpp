#include <string>

#include "utilities.h"
#include "Player.h"
#include "Card.h"
#include "Merchant.h"

Merchant::Merchant() : Card("Merchant") {}

static int getUserAction() {
    std::string userInput;
    std::getline(std::cin, userInput);

    int playerChoice;
    bool hasGottenValidInput = false;
    while (!hasGottenValidInput) {
        try {
            playerChoice = std::stoi(userInput.c_str());
        } catch (std::invalid_argument) {
            printInvalidInput();
            continue;
        }
        hasGottenValidInput = true;
    }
}

static void applyHealPotion(Player &player) {
    player.heal(1);
}
static void applyForceBoost(Player &player) {
    player.buff(1);
}

void Merchant::applyEncounter(Player &player) const  {

    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());

    int playerChoice = getUserAction();

    int cost = 0;
    switch (playerChoice) {
    case static_cast<int>(Merchant::Action::Nothing):
        break;
    case static_cast<int>(Merchant::Action::HealthBoost):
        cost = healCost;
        if (Player.pay(cost)) {
            applyHealPotion(player)
        } else {
            printMerchantInsufficientCoins(std::cout);
        }
        break;
    case static_cast<int>(Merchant::Action::ForceBoost):
        cost = forceCost;
        if (Player.pay(cost)) {
            applyForceBoost(player)
        } else {
            printMerchantInsufficientCoins(std::cout);
        }
        break;
    default:
        printInvalidInput();
        break;
    }
    
    printMerchantSummary(std::cout, player.getName(), playerChoice, cost);
}
