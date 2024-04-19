#pragma once

#include "pos.h"

enum Dir {
  Forward = 1, Back = -1, Stop = 0
};

class Direction {
private:
  Dir _y;
  Dir _x;
public:
  Direction(Dir y, Dir x);
  void updateDirectionByPositions(PosDouble from, PosDouble to);
  Dir y();
  Dir x();
  void setY(Dir y);
  void setX(Dir y);
};