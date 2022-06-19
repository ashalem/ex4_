#include <string>

#include "../utilities.h"
#include "../Players/Player.h"
#include "Card.h"
#include "Treasure.h"

Treasure::Treasure() : Card("Treasure") {}

void Treasure::applyEncounter(Player &player) const  {
    player.addCoins(10);
    printTreasureMessage();
}