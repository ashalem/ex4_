#include <stdbool.h>
#include <string>
#include <iostream>

#include "utilities.h"
#include "BattleCard.h"
#include "Dragon.h"

Dragon::Dragon(): BattleCard(25, 0, 1000, "Dragon") {}


void handleLoss(Player &player) const {
    player.kill();
}