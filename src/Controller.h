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
    const InitDataFieldsIsWall getInitFieldsIsWall();
    const InitDataFieldsCoin getInitFieldsCoin();
    const InitDataSuperCoinsData getInitSuperCoinsData();
    const InitDataPortalsData getInitPorlatsData();
    void drawView();
    void alternateEntitiesStateView();
    void listenForClicks();
    void moveEntities();
public:
    GameController(ViewUnits viewUnits, double timeUnit);
    void gameLoop();
};