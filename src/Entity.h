#pragma once

#include "View.h"
#include "pos.h"
#include "raylib.h"

class Entity {
private:
  PosDouble _pos;
  Direction _speedDir;
public:
  Entity(PosDouble startPos, Direction startDir);
  void move();
  void setSpeedDir(Direction speedDir);
	PosDouble getPos();
};