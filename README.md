# matchmaking_system

## Descrição do Projeto

Esse projeto se trata de um sistema escrito em C++ que tem como objetivo
a formação de grupos para partidas de um jogo online. O sistema recebe chamadas
de jogadores para que entrem na fila de espera, então ordena os jogadores
de acordo com sua habilidade, medida com um atributo de pontuação. A ordenação da fila
pode tanto ser por insertion sort bem como merge sort. A aplicação também permite
remoção de jogadores da fila de espera e a formação de grupos de diversos tamanhos
e disparidade de habilidade.

## Instruções de Compilação

O projeto é composto por múltiplos arquivos .cpp e .hpp. Para compilar
utilizando o g++, utilize o comando abaixo no terminal:

```bash
g++ main.cpp Matchmaking.cpp Player.cpp -o matchmaking
```

## Instruções de Execução

Para executar a aplicação basta utilizar o seguinte comando no terminal:

```bash
./matchmaking
```

## Organização dos Arquivos

* Matchmaking.cpp/.hpp: Onde está a classe Matchmaking responsável pelo gerenciamento de jogadores na fila de espera:

  * players: Fila de espera de jogadores com tamanho máximo de 10.000
  
  * size: Número atual de jogadores esperando para encontrar uma partida
  
* Player.cpp/.hpp: Localização da classe Player que representa o jogador.
Possui informações básicas do usuário e informações responsáveis pela colocação na fila de espera:

  * id: Identificador único do jogador
  
  * name: Nome do usuário
  
  * score: Pontuação que diz o quão bom é aquele jogador
  
  * timestamp: Momento em que o jogador deu entrada na fila de espera (Critério de desempate)
  

* main.cpp: Driver code da nossa aplicação responsável por instancear as classes e utilizar seus métodos. 
