#pragma once

#include "Model.h"
#include "View.h"

class GameController {
private:
    GameView *_view;
    GameModel *_model;
    InitDataFieldsIsWall getInitFieldsIsWall();
    InitDataFieldsCoin getInitFieldsCoin();
    InitDataSuperCoinsData getInitSuperCoinsData();
    InitDataPorlatsData getInitPorlatsData();
public:
    GameController();
    void drawView();
    void listenForClicks();
    void moveEntities();
};