#include <iostream>
#include "../Mtmchkin.h"
#include "../Exception.h"

int main() {
    const int MAX_NUMBER_OF_ROUNDS = 100;
    try {
        Mtmchkin game("AE_deck.txt");
        while(!game.isGameOver() && game.getNumberOfRounds() < MAX_NUMBER_OF_ROUNDS){
            game.playRound();
            game.printLeaderBoard();
        }
        game.printLeaderBoard();
    } catch (const std::runtime_error& e) {
        //const MtmchinException& A = e;
        std::cerr << e.what() << std::endl;
        return 0;
    }

    return 0;
}
