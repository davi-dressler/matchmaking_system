#include "Player.hpp"

Player::Player() {
    this->id = -1;
    this->score = 0;
    this->timestamp = 0;
    this->name = "";
}

Player::Player(int id, std::string name, int score, int timestamp) {
  this->id = id;
  this->name = name;
  this->score = score;
  this->timestamp = timestamp;
}

Player::~Player() = default;

int Player::getId() {
  return this->id;
}
std::string Player::getName() {
  return this->name;
}
int Player::getScore() {
  return this->score;
}
int Player::getTimestamp() {
  return this->timestamp;
}
