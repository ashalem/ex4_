CC=g++
PLAYERS_OBJS = Players/Player.o Players/Fighter.o Players/Wizard.o Players/Rogue.o 
CARDS_OBJS = Cards/Card.o Cards/BattleCard.o Cards/Fairy.o Cards/Pitfall.o Cards/Barfight.o Cards/Dragon.o Cards/Vampire.o Cards/Goblin.o Cards/Gang.o Cards/Treasure.o Cards/Merchant.o  
OBJS= Mtmchkin.o utilities.o $(PLAYERS_OBJS) $(CARDS_OBJS)
DEBUG_FLAG= -g
CPPFLAGS=--std=c++11 -Wall -pedantic-errors -Werror  -DNDEBUG -g

tester : $(OBJS) test.o
	$(CC) $(DEBUG_FLAG) $(CPPFLAGS) $(OBJS) test.o -o $@

main_tester: $(OBJS) tool/main.o
	$(CC) $(DEBUG_FLAG) $(CPPFLAGS) $(OBJS) tool/main.o -o $@


utilities.o: utilities.cpp utilities.h Players/Player.h Exception.h
Cards/Card.o: Cards/Card.cpp Cards/Card.h Players/Player.h utilities.h
Cards/BattleCard.o: Cards/BattleCard.cpp Cards/BattleCard.h Players/Player.h utilities.h
Cards/Dragon.o: Cards/Dragon.cpp Cards/Dragon.h Cards/BattleCard.h Players/Player.h utilities.h
Cards/Vampire.o: Cards/Vampire.cpp Cards/Vampire.h Cards/BattleCard.h Players/Player.h utilities.h
Cards/Goblin.o: Cards/Goblin.cpp Cards/Goblin.h Cards/BattleCard.h Players/Player.h utilities.h
Cards/Gang.o: Cards/Gang.cpp Cards/Gang.h Cards/BattleCard.h Players/Player.h utilities.h
Players/Player.o: Players/Player.cpp Players/Player.h utilities.h
Cards/Fairy.o: Cards/Fairy.cpp Cards/Fairy.h Cards/Card.h Players/Player.h utilities.h
Cards/Barfight.o: Cards/Barfight.cpp Cards/Barfight.h Cards/Card.h Players/Player.h utilities.h
Cards/Pitfall.o: Cards/Pitfall.cpp Cards/Pitfall.h Cards/Card.h Players/Player.h utilities.h
Players/Fighter.o: Players/Fighter.cpp Players/Fighter.h Players/Player.h utilities.h
Players/Rogue.o: Players/Rogue.cpp Players/Rogue.h Players/Player.h utilities.h
Players/Wizard.o: Players/Wizard.cpp Players/Wizard.h Players/Player.h utilities.h
Mtmchkin.o: Mtmchkin.cpp  Mtmchkin.h
test.o: test.cpp
tool/main.o: tool/main.cpp

clean:
	rm -f test.o tool/main.o $(OBJS) $(EXEC)
