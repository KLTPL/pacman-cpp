#pragma once

#include "modelTypes.h"

class GameView {
private:
    int _fieldSizePx;
    BoardDataRefForView _boardDataRef;
public:
    GameView(BoardDataRefForView boardDataRef, int fieldSizePx);
    void draw(GameStatusForView gameStatus);
};
