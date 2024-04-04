#pragma once

#include "Model.h"
#include "View.h"
#include "Timer.h"

class GameController {
private:
    GameView *_view;
    GameModel *_model;
    Timer *_timer;
    InitDataFieldsIsWall getInitFieldsIsWall();
    InitDataFieldsCoin getInitFieldsCoin();
    InitDataSuperCoinsData getInitSuperCoinsData();
    InitDataPorlatsData getInitPorlatsData();
    void drawView();
    void listenForClicks();
    void moveEntities();
public:
    GameController();
    void gameLoop();
};