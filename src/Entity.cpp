#include "Entity.h"

Entity::Entity(PosDouble startPos, Direction startSpeedDir) {
  this->_pos = startPos;
  this->_speedDir = startSpeedDir;
}

void Entity::move() {
  this->_pos.x += this->_speedDir.x * this->_speed;
  this->_pos.y += this->_speedDir.y * this->_speed;
}

PosInt Entity::calcNextPos() {
  return {
    int(this->_pos.y) + this->_speedDir.y,
    int(this->_pos.x) + this->_speedDir.x
  };
}

bool Entity::isInFieldCenter() {
  return (
    this->_pos.x == int(this->_pos.x) &&
    this->_pos.y == int(this->_pos.y)
  );
}

void Entity::setSpeedDir(Direction speedDir) {
  this->_speedDir = speedDir;
}


PosDouble Entity::getPos() {
  return this->_pos;
}

Direction Entity::getSpeedDir() {
  return this->_speedDir;
}
