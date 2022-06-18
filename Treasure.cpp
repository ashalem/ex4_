#include <string>

#include "utilities.h"
#include "Player.h"
#include "Card.h"
#iclude "Treasure.h"

Treasure::Treasure() : Card("Treasure") {}

void Treasure::applyEncounter(Player &player) const  {
    player.addCoins(10);
    printTreasureMessage();
}