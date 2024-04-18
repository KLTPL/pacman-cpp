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
    InitDataFieldsIsWall getInitFieldsIsWall();
    InitDataFieldsCoin getInitFieldsCoin();
    InitDataSuperCoinsData getInitSuperCoinsData();
    InitDataPortalsData getInitPorlatsData();
    void drawView();
    void listenForClicks();
    void moveEntities();
public:
    GameController(ViewUnits viewUnits, double timeUnit);
    void gameLoop();
};