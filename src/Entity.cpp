#include "Entity.h"

Entity::Entity(PosDouble startPos, Direction startDir) {
  this->_pos = startPos;
}

void Entity::move() {
  this->_pos.x += this->_speedDir.x;
  this->_pos.y += this->_speedDir.y;
}

void Entity::setSpeedDir(Direction speedDir) {
  this->_speedDir = speedDir;
}

PosDouble Entity::getPos() {
  return this->_pos;
}