#pragma once
#include "pos.h"
#include "Direction.h"

typedef struct ViewUnits {
    int fieldSizePx;
    int boardHeight;
    int screenWidth;
    int bottomBarHeight;
    int fieldsX;
    int fieldsY;
} ViewUnits;

typedef struct InitPacmanData {
    PosDouble pos;
    Direction direction;
} InitPacmanData;