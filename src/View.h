#pragma once

#include "modelTypes.h"
#include "controllerTypes.h"
#include "viewUtils.h"

class GameView {
private:
    ViewUnits _units;
    int _gameTickCount = 0;
    bool _isEntityState1 = true;
    const PacmanImageData _pacmanImageData;
    void drawWalls(const BoardDataRefForView &boardDataRef);
    void drawPacman(const BoardDataRefForView &boardDataRef);
    void drawCoins(const BoardDataRefForView &boardDataRef);
    void drawBottomBar(const BoardDataRefForView &boardDataRef);
public:
    GameView(ViewUnits units);
    void draw(const BoardDataRefForView &boardDataRef);
    void alternateEntityState();
};
