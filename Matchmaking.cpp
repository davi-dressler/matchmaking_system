#include "Matchmaking.hpp"
#include "Player.hpp"

bool Matchmaking::insert(Player player) {
  if (this->size == MAX_PLAYERS){
    return false;
  }

  this->players[size] = player;
  this->size++;

  return true;
}
