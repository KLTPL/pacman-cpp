#pragma once

#include "controllerTypes.h"
#include "Model.h"
#include "View.h"
#include "Timer.h"

class GameController {
private:
    double _timeUnit;
    Timer _timer;
    GameModel _model;
    GameView _view;
    bool _isGameRunning = true;
    const InitDataFieldsIsWall _getInitFieldsIsWall();
    const InitDataFieldsCoin _getInitFieldsCoin();
    const InitDataSuperCoinsData _getInitSuperCoinsData();
    const InitDataPortalsData _getInitPorlatsData();
    const InitPacmanData _getInitPacmanData();
    const PosDouble _getInitStartGhostPos();
    const int _getInitCoinsAmount();
    const int _getInitGhostsAmount();
    void _drawView();
    void _alternateEntitiesStateView();
    void _listenForClicks();
    void _moveEntities();
public:
    GameController(ViewUnits viewUnits, double timeUnit);
    void gameLoop();
};