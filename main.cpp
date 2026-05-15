#include <iostream>
#include "Matchmaking.hpp"
#include "Player.hpp"

using namespace std;

int main(){
    Matchmaking match;

    match.insert(Player(2, "Larissa", 1040, 5));
    match.insert(Player(3, "Pedro",   1020, 3));
    match.insert(Player(5, "Samuel",  1010, 4));
    // Jogadores empatados
    match.insert(Player(1, "Ana",     1070, 10));
    match.insert(Player(4, "Sodré",   1070, 11));

    cout << "Antes do Insertion Sort" << endl;
    match.printWaitingPlayers();
    match.sortByScoreInsertion();
    cout << endl;
    cout << "Depois do Insertion Sort" << endl;
    match.printWaitingPlayers();

    match.insert(Player(6, "João", 1270, 12));
    match.insert(Player(7, "Lara", 1010, 9));

    cout << endl;
    cout << "Antes do Merge Sort" << endl;
    match.printWaitingPlayers();
    match.sortByScoreMerge();
    cout << "Depois do Merge Sort" << endl;
    match.printWaitingPlayers();
    cout << endl;

    match.removePlayer(1);
    cout << "Depois de remover Ana" << endl;
    match.printWaitingPlayers();
    cout << endl;

    int gsize1;
    match.formGroup(3, 10, &gsize1);
    cout << "Formação bem sucedida de grupo" << endl;
    match.printWaitingPlayers();
    cout << endl;

    int gsize2;
    cout << "Formação mal sucedida de grupo" << endl;
    match.formGroup(2, 1, &gsize2);
    match.printWaitingPlayers();


    return 0;

}
