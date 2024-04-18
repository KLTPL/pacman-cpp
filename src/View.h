#pragma once

#include "modelTypes.h"
#include "controllerTypes.h"

class GameView {
private:
    ViewUnits _units;
    void drawWalls(const BoardDataRefForView &boardDataRef);
    void drawPacman(const BoardDataRefForView &boardDataRef);
    void drawCoins(const BoardDataRefForView &boardDataRef);
    void drawBottomBar(const BoardDataRefForView &boardDataRef);
public:
    GameView(ViewUnits units);
    void draw(const BoardDataRefForView &boardDataRef);
};
