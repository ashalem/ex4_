#include <stdbool.h>
#include <string>
#include <iostream>

#include "utilities.h"
#include "BattleCard.h"
#include "Vampire.h"

Vampire::Vampire() : BattleCard(10, 10, 2, "Vampire") {}


void Vampire::handleLoss(Player &player) const {
    player.debuff(1);
}