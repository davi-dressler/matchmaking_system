#include <iostream>
#include "Matchmaking.hpp"
#include "Player.hpp"

int main(){
    Matchmaking match;

    match.insert(Player(1, "Ana", 1070, 10));
    match.insert(Player(2, "Ana", 1010, 2));
    match.insert(Player(3, "Ana", 1020, 3));
    match.insert(Player(4, "Ana", 1030, 4));
    match.insert(Player(5, "Ana", 1050, 5));

    match.removePlayer(2);
    match.sortByScoreInsertion();
    match.printWaitingPlayers();

    return 0;

}