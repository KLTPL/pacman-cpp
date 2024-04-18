#pragma once

#include "controllerTypes.h"
#include "Model.h"
#include "View.h"
#include "Timer.h"

class GameController {
private:
    GameView *_view;
    GameModel *_model;
    Timer *_timer;
    double _timeUnit;
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