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

//Verificar implementação
//vamos usar array circular?
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

//Verificar implementação
//Adicionar critério desempate
void Matchmaking::sortByScoreInsertion() {
  for(int j = 1; j < this->size; j++){
    Player p_atual = this->players[j];
    int i = j - 1;

    while(i >= 0 && this->players[i].getScore() > p_atual.getScore()){
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
//   deve retornar um novo array alocado dinamicamente contendo cópias dos jogadores atualmente armazenados no sistema.

// Além disso:

// o parâmetro n deve ser utilizado para informar a quantidade de jogadores retornados;
// caso não existam jogadores, o método deve retornar nullptr e definir *n = 0;
// a memória alocada para o array retornado deve ser liberada por quem chamou a função, utilizando delete[].
}

//Verficar implementação
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