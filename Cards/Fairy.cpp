#include <string>

#include "../utilities.h"
#include "../Players/Player.h"
#include "Card.h"
#include "Fairy.h"

Fairy::Fairy() : Card("Fairy") {}

void Fairy::applyEncounter(Player &player) const  {
    if(player.getClass() == "Wizard") {
        printFairyMessage(1);
        return;
    }

    player.heal(10);
    printFairyMessage(0);
}