#include "Ghost.h"
#include "Entity.h"
#include "pos.h"
#include "Direction.h"
#include <iostream>

Ghost::Ghost(PosDouble startPos, std::vector<PosInt> currPath):
  Entity(startPos, {Dir::Stop, Dir::Stop}),
  _currPath(currPath)
{
  this->updateDirectionFromCurrPath();
}

void Ghost::updateDirectionFromCurrPath() {
  if (this->_currPath.size() <= 0) {
    return;
  }
  PosInt newPos = this->_currPath[0];
  this->_currPath.erase(this->_currPath.begin());

  Direction newDirection = Direction(Dir::Stop, Dir::Stop);
  newDirection.updateDirectionByPositions(
    this->getPos(), 
    PosDouble{double(newPos.y), double(newPos.x)}
  );
  this->setDirection(newDirection);
}

bool Ghost::isPathEmpty() {
  return this->_currPath.size() == 0;
}

void Ghost::setPath(std::vector<PosInt> newPath) {
  this->_currPath = newPath;
}