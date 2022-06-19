MTM_HEADERS=/home/mtm/public/2122b/ex4_
CC=g++
OBJS=utilities.o Card.o Fairy.o Pitfall.o Barfight.o Players/Player.o Players/Fighter.o Players/Wizard.o Players/Rogue.o  
EXEC=eden_test
DEBUG_FLAG= -g
CPPFLAGS=--std=c++11 -Wall -pedantic-errors -Werror -I. -IPlayers -I$(MTM_HEADERS) -DNDEBUG -g

$(EXEC) : $(OBJS)
	$(CC) $(DEBUG_FLAG) $(CPPFLAGS) $(OBJS) -o $@


utilities.o: utilities.cpp utilities.h Players/Player.h Exception.h
Card.o: Card.cpp Card.h Players/Player.h utilities.h
Players/Player.o: Players/Player.cpp Players/Player.h utilities.h
Fairy.o: Fairy.cpp Fairy.h Card.h Players/Player.h utilities.h
Barfight.o: Barfight.cpp Barfight.h Card.h Players/Player.h utilities.h
Pitfall.o: Pitfall.cpp Pitfall.h Card.h Players/Player.h utilities.h
Players/Fighter.o: Players/Fighter.cpp Players/Fighter.h Players/Player.h utilities.h
Players/Rogue.o: Players/Rogue.cpp Players/Rogue.h Players/Player.h utilities.h
Players/Wizard.o: Players/Wizard.cpp Players/Wizard.h Players/Player.h utilities.h

clean:
	rm -f $(OBJS) $(EXEC)
