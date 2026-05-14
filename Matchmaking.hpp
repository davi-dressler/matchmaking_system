#ifndef MATCHMAKING_HPP
#define MATCHMAKING_HPP

#include "Player.hpp"

const int MAX_PLAYERS = 100000;

class Matchmaking {

private:

    Player* players;
    int size;

public:

    Matchmaking();
    ~Matchmaking();

    bool insert(Player player);
    bool removePlayer(int id);

    bool comparePlayer(Player player_1, Player player_2);

    void sortByScoreInsertion();
    void sortByScoreMerge();
    Player* mergeSort(Player arr[], int n);
    Player* merge(Player arr1[], int n, Player arr2[], int m);

    Player* formGroup(int groupSize, int delta, int* n);

    Player* getWaitingPlayers(int* n);

    void printWaitingPlayers();

    // Outros métodos auxiliares, se necessário
};

#endif
