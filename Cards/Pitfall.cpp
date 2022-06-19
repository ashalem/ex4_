#include <string>

#include "../utilities.h"
#include "../Players/Player.h"
#include "Card.h"
#include "Pitfall.h"

Pitfall::Pitfall() : Card("Pitfall") {}

void Pitfall::applyEncounter(Player &player) const {
    if(player.getClass() == "Rogue") {
        printPitfallMessage(1);
        return;
    }

    player.damage(10);
    printPitfallMessage(0);
}