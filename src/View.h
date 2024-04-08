#pragma once

#include "modelTypes.h"
#include "controllerTypes.h"

class GameView {
private:
    ViewUnits _units;
    BoardDataRefForView _boardDataRef;
    void drawWalls();
    void drawPacman(const GameStatusForView &gameStatus);
    void drawCoins();
    void drawBottomBar();
public:
    GameView(BoardDataRefForView boardDataRef, ViewUnits units);
    void draw(const GameStatusForView &gameStatus);
};
