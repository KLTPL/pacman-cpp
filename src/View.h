#pragma once

#include "modelTypes.h"

class GameView {
private:
    int _fieldSizePx;
    BoardDataRefForView _boardDataRef;
    void drawWalls();
    void drawPacman(const GameStatusForView &gameStatus);
    void drawCoins();
public:
    GameView(BoardDataRefForView boardDataRef, int fieldSizePx);
    void draw(const GameStatusForView &gameStatus);
};
