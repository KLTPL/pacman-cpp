#include "Entity.h"

Entity::Entity(PosDouble startPos, Direction startDirection): 
  _pos(startPos), 
  _direction(startDirection) 
{}

void Entity::move() {
  this->_pos.x += this->_direction.x * this->_speed;
  this->_pos.y += this->_direction.y * this->_speed;
}

PosInt Entity::calcNextPos() {
  return {
    int(this->_pos.y) + this->_direction.y,
    int(this->_pos.x) + this->_direction.x
  };
}

bool Entity::isInFieldCenter() {
  return (
    this->_pos.x == int(this->_pos.x) &&
    this->_pos.y == int(this->_pos.y)
  );
}

void Entity::setDirection(Direction direction) {
  this->_direction = direction;
}


PosDouble Entity::getPos() {
  return this->_pos;
}

Direction Entity::getDirection() {
  return this->_direction;
}
