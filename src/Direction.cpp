#include "Direction.h"

Direction::Direction(Dir y, Dir x):
  _y(y),
  _x(x)
{}

void Direction::updateDirectionByPositions(PosDouble from, PosDouble to) {
  auto substractionY = to.y - from.y;
  auto substractionX = to.x - from.x;
  Dir dirY;
  Dir dirX;
  if (substractionY == 0) {
    dirY = Dir::Stop;
  } else if (substractionY > 0) {
    dirY = Dir::Forward;
  } else {
    dirY = Dir::Back;
  }
  if (substractionX == 0) {
    dirX = Dir::Stop;
  } else if (substractionX > 0) {
    dirX = Dir::Forward;
  } else {
    dirX = Dir::Back;
  }
  this->setY(dirY);
  this->setX(dirX);
}

Dir Direction::y() {
  return this->_y;
}
Dir Direction::x() {
  return this->_x;
}
void Direction::setY(Dir y) {
  this->_y = y;
}
void Direction::setX(Dir x) {
  this->_x = x;
}