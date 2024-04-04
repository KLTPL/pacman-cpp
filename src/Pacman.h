#pragma once

#include "Entity.h"
#include "pos.h"

class Pacman : public Entity {
public:
  Pacman(PosDouble startPos, Direction startDir);
};