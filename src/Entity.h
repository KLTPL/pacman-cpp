#pragma once

#include "View.h"
#include "pos.h"
#include "Direction.h"

class Entity {
private:
  PosDouble _pos;
  double _speed = 0.125;
  Direction _direction;
public:
  Entity(PosDouble startPos, Direction startDirection);
  void move();
  PosInt calcNextPos();
  bool isInFieldCenter();
  void setDirection(Direction direction);
	PosDouble getPos();
  Direction getDirection();
};