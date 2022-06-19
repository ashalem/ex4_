#include <string>

#include "../utilities.h"
#include "../Players/Player.h"
#include "Card.h"
#include "Barfight.h"

Barfight::Barfight() : Card("Barfight") {}

void Barfight::applyEncounter(Player &player) const {
    if(player.getClass() == "Fighter") {
        printBarfightMessage(1);
        return;
    }

    player.damage(10);
    printBarfightMessage(0);
}