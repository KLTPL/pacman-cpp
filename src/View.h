#pragma once

#include "modelTypes.h"

class GameView {
private:
    int _fieldSizePx;
    int _boardHeight;
    int _screenWidth;
    int _bottomBarHeight;
    BoardDataRefForView _boardDataRef;
    void drawWalls();
    void drawPacman(const GameStatusForView &gameStatus);
    void drawCoins();
    void drawBottomBar();
public:
    GameView(BoardDataRefForView boardDataRef, int fieldSizePx, int screenWidth, int boardHeight, int bottomBarHeight);
    void draw(const GameStatusForView &gameStatus);
};
