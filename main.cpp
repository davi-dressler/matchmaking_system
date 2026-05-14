#include <iostream>
#include "Matchmaking.hpp"
#include "Player.hpp"

int main(){
    Matchmaking match;

    match.insert(Player(1, "Ana", 1070, 10));
    match.insert(Player(2, "Ana", 1070, 5));
    match.insert(Player(3, "Ana", 1070, 3));
    match.insert(Player(4, "Ana", 1070, 11));
    match.insert(Player(5, "Ana", 1070, 4));

    match.sortByScoreInsertion();
    match.printWaitingPlayers();

    return 0;

}