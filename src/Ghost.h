#pragma once

#include "pos.h"
#include "Entity.h"
#include <vector>
#include "Direction.h"

class Ghost : public Entity {
private:
  std::vector<PosInt> _currPath;
public:
  Ghost(PosDouble startPos, Direction startDirection, std::vector<PosInt> currPath);
  void updateDirectionFromCurrPath();
};