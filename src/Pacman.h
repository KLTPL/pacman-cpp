#pragma once

#include "Entity.h"
#include "pos.h"
#include "Direction.h"

class Pacman : public Entity {
private:
  Direction _nextdirection;
public:
  Pacman(PosDouble startPos, Direction startDir);
  void updateDirection();
  PosInt calcNextPos(bool useCurrDir);
  bool isNextDirTurningBack();
  bool isStopped();
  void setNextDirection(Direction newNextDirection);
};