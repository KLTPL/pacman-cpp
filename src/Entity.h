#pragma once

#include "View.h"
#include "pos.h"
#include "raylib.h"

class Entity {
protected:
  PosDouble _pos;
  double _speed = 0.125;
  Direction _speedDir;
public:
  Entity(PosDouble startPos, Direction startSpeedDir);
  void move();
  PosInt calcNextPos();
  bool isInFieldCenter();
  void setSpeedDir(Direction speedDir);
	PosDouble getPos();
  Direction getSpeedDir();
};