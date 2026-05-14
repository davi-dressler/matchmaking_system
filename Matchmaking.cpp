#include <iostream>
#include "Matchmaking.hpp"
#include "Player.hpp"


Matchmaking::Matchmaking() {
    this->players = new Player[MAX_PLAYERS];  
    this->size = 0;
}


Matchmaking::~Matchmaking() {
    delete[] this->players; 
}


bool Matchmaking::insert(Player player) {
  if (this->size == MAX_PLAYERS){
    return false;
  }

  this->players[size] = player;
  this->size++;

  return true;
}


bool Matchmaking::removePlayer(int id){
  for(int i = 0; i < this->size; i++){
    int player_id = this->players[i].getId();

    if(player_id == id){
      for(int j = i; j <= this-> size; j++){
        this->players[j] = players[j+1];
      }
      this->size--;
      return true;
    }
  }
  return false;
}


bool Matchmaking::comparePlayer(Player player_1, Player player_2){
  if(player_1.getScore() > player_2.getScore()){
    return true;
  }
  if(player_1.getScore() == player_2.getScore()){
    if(player_1.getTimestamp() > player_2.getTimestamp()){
      return true;
    }
    return false;
  }
  return false;
}


void Matchmaking::sortByScoreInsertion() {
  for(int j = 1; j < this->size; j++){
    Player p_atual = this->players[j];
    int i = j - 1;

    while(i >= 0 && comparePlayer(this->players[i], p_atual)){
      this->players[i + 1] = this->players[i];
      i--;
    }

    this->players[i + 1] = p_atual;
  }
}


void Matchmaking::sortByScoreMerge(){
  
}


Player* Matchmaking::formGroup(int groupSize, int delta, int* n){

  if(groupSize > this->size){
    *n = 0;
    return nullptr;
  }

  for(int i = 0; i <= this->size - groupSize; i++){
    int min_score = this->players[i].getScore(); 
    int max_score = this->players[i + groupSize - 1].getScore();

    if(min_score - max_score <= delta){
      Player* group = new Player[groupSize];
      for(int j = i; j <= i + groupSize - 1; j++){
        group[j - i] = this->players[i];
        removePlayer(players[i].getId());
      }

    *n = groupSize;
    return group;
    }
  }

  *n = 0;
  return nullptr;

}


Player* Matchmaking::getWaitingPlayers(int* n){
  if(this->size = 0){
    *n = 0;
    return nullptr;
  }

  Player* waiting_players = new Player[size];

  for(int i = 0; i < size; i++){
    waiting_players[i] = this->players[i];
  }

  *n = this->size;
  return waiting_players;

}


void Matchmaking::printWaitingPlayers() {
  std::cout << "Waiting Players:" << std::endl;
  
  for (int i = 0; i < this->size; i++) {   // < em vez de <=
      Player& p = this->players[i];
      std::cout << "[" << p.getId() << " | "
                << p.getName()      << " | "
                << p.getScore()     << " | "
                << p.getTimestamp() << "]" << std::endl;
  }
}