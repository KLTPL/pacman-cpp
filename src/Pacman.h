#pragma once

#include "Entity.h"
#include "pos.h"

class Pacman : public Entity {
private:
  Direction _nextSpeedDir;
public:
  Pacman(PosDouble startPos, Direction startDir);
  void listenForClicks();
  void updateSpeedDir();
  PosInt calcNextPos(bool useCurrDir);
  bool isNextDirTurningBack();
  bool isStopped();
};