#include "Ghost.h"
#include "Entity.h"
#include "pos.h"
#include "Direction.h"
#include <iostream>

Ghost::Ghost(PosDouble startPos, Direction startDirection, std::vector<PosInt> currPath):
  Entity(startPos, startDirection),
  _currPath(currPath)
{
  this->updateDirectionFromCurrPath();
}

void Ghost::updateDirectionFromCurrPath() {
  if (this->_currPath.size() <= 0) {
    return;
  }
  PosInt newPos = this->_currPath[0];
  this->_currPath.erase(this.begin());

  Direction newDirection = Direction(Dir::Stop, Dir::Stop);
  newDirection.updateDirectionByPositions(
    this->getPos(), 
    PosDouble{double(newPos.y), double(newPos.x)}
  );
  this->setDirection(newDirection);
}