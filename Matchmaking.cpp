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

//Verificar implementação
//vamos usar array circular?
bool Matchmaking::removePlayer(int id){
  for(int i = 0; i <= this->size; i++){
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
void Matchmaking::sortByScoreInsertion() {
  for(int j = 1; j <= this->size; j++){
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

// deve tentar formar um grupo com groupSize jogadores.

// O método assume que os jogadores já estão ordenados por score.

// Caso um grupo válido seja encontrado:

// o método deve retornar um novo array alocado dinamicamente contendo os jogadores do grupo;
// o parâmetro n deve receber o valor de groupSize;
// os jogadores escolhidos devem ser removidos da fila de espera.
// Caso nenhum grupo válido seja encontrado:

// o método deve retornar nullptr;
// o parâmetro n deve receber o valor 0;
// nenhum jogador deve ser removido da fila.
// A memória alocada para o array retornado deve ser liberada por quem chamou a função, utilizando delete[].
}

Player* Matchmaking::getWaitingPlayers(int* n){
//   deve retornar um novo array alocado dinamicamente contendo cópias dos jogadores atualmente armazenados no sistema.

// Além disso:

// o parâmetro n deve ser utilizado para informar a quantidade de jogadores retornados;
// caso não existam jogadores, o método deve retornar nullptr e definir *n = 0;
// a memória alocada para o array retornado deve ser liberada por quem chamou a função, utilizando delete[].
}

//Verficar implementação
void Matchmaking::printWaitingPlayers(){
  std::cout << "Waiting Players:" << std::endl;
  for(int i = 0; i <= size; i++){
    Player player = this->players[i];
    std::cout << "[" << player.getId() << " | " << player.getName() << " | " << player.getScore() << " | " << player.getTimestamp() << "]" << std::endl;
  }
}