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
    void _drawWalls(const BoardDataRefForView &boardDataRef);
    void _drawPacman(const BoardDataRefForView &boardDataRef);
    void _drawGhosts(const BoardDataRefForView &boardDataRef);
    void _drawCoins(const BoardDataRefForView &boardDataRef);
    void _drawBottomBar(const BoardDataRefForView &boardDataRef);
public:
    GameView(ViewUnits units);
    void draw(const BoardDataRefForView &boardDataRef);
    void alternateEntityState();
};
