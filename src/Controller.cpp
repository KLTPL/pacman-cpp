#include "Controller.h"
#include "utils.h"
#include "Model.h"
#include "View.h"

InitDataFieldsIsWall GameController::getInitFieldsIsWall() {
    InitDataFieldsIsWall ret = { // positive - amount of walls, negative - amount of empty fields
        {28},
        {1, -6, 2, -10, 2, -6, 1},
        {1, -1, 4, -1, 2, -1, 8, -1, 2, -1, 4, -1, 1},
        {1, -1, 4, -1, 2, -1, 8, -1, 2, -1, 4, -1, 1},
        {1, -26, 1},
        {3, -1, 2, -1, 5, -1, 2, -1, 5, -1, 2, -1, 3},
        {3, -1, 2, -1, 5, -1, 2, -1, 5, -1, 2, -1, 3},
        {3, -1, 2, -1, 5, -1, 2, -1, 5, -1, 2, -1, 3},
        {-4, 2, -7, 2, -7, 2, -4},
        {3, -1, 5, -1, 8, -1, 5, -1, 3},
        {3, -1, 5, -1, 8, -1, 5, -1, 3},
        {3, -22, 3},
        {3, -1, 5, -1, 8, -1, 5, -1, 3},
        {3, -1, 5, -1, 8, -1, 5, -1, 3},
        {3, -1, 2, -4, 8, -4, 2, -1, 3},
        {3, -1, 2, -1, 2, -1, 8, -1, 2, -1, 2, -1, 3},
        {3, -1, 2, -1, 2, -1, 8, -1, 2, -1, 2, -1, 3},
        {-7, 2, -10, 2, -7},
        {3, -1, 8, -1, 2, -1, 8, -1, 3},
        {3, -1, 8, -1, 2, -1, 8, -1, 3},
        {3, -10, 2, -10, 3},
        {3, -1, 5, -1, 8, -1, 5, -1, 3},
        {3, -1, 5, -1, 8, -1, 5, -1, 3},
        {1, -26, 1},
        {1, -1, 4, -1, 5, -1, 2, -1, 5, -1, 4, -1, 1},
        {1, -1, 4, -1, 5, -1, 2, -1, 5, -1, 4, -1, 1},
        {1, -1, 4, -1, 2, -4, 2, -4, 2, -1, 4, -1, 1},
        {1, -1, 4, -1, 2, -1, 8, -1, 2, -1, 4, -1, 1},
        {1, -1, 4, -1, 2, -1, 8, -1, 2, -1, 4, -1, 1},
        {1, -26, 1},
        {28}
    };
    return ret;
}

InitDataFieldsCoin GameController::getInitFieldsCoin() {
    InitDataFieldsCoin ret = {
        {28},
        {1, -6, 2, -10, 2, -6, 1},
        {1, -1, 4, -1, 2, -1, 8, -1, 2, -1, 4, -1, 1},
        {1, -1, 4, -1, 2, -1, 8, -1, 2, -1, 4, -1, 1},
        {1, -26, 1},
        {3, -1, 2, -1, 5, -1, 2, -1, 5, -1, 2, -1, 3},
        {3, -1, 2, -1, 5, -1, 2, -1, 5, -1, 2, -1, 3},
        {3, -1, 2, -1, 5, -1, 2, -1, 5, -1, 2, -1, 3},
        {3, -1, 2, -7, 2, -7, 2, -1, 3},
        {3, -1, 5, 1, 8, 1, 5, -1, 3},
        {3, -1, 5, 1, 8, 1, 5, -1, 3},
        {3, -1, 20, -1, 3},
        {3, -1, 5, 1, 8, 1, 5, -1, 3},
        {3, -1, 5, 1, 8, 1, 5, -1, 3},
        {3, -1, 2, 4, 8, 4, 2, -1, 3},
        {3, -1, 2, 1, 2, 1, 8, 1, 2, 1, 2, -1, 3},
        {3, -1, 2, 1, 2, 1, 8, 1, 2, 1, 2, -1, 3},
        {3, -1, 3, 2, 10, 2, 3, -1, 3},
        {3, -1, 8, 1, 2, 1, 8, -1, 3},
        {3, -1, 8, 1, 2, 1, 8, -1, 3},
        {3, -7, 3, 2, 3, -7, 3},
        {3, -1, 5, -1, 8, -1, 5, -1, 3},
        {3, -1, 5, -1, 8, -1, 5, -1, 3},
        {1, -12, 2, -12, 1},
        {1, -1, 4, -1, 5, -1, 2, -1, 5, -1, 4, -1, 1},
        {1, -1, 4, -1, 5, -1, 2, -1, 5, -1, 4, -1, 1},
        {1, -1, 4, -1, 2, -4, 2, -4, 2, -1, 4, -1, 1},
        {1, -1, 4, -1, 2, -1, 8, -1, 2, -1, 4, -1, 1},
        {1, -1, 4, -1, 2, -1, 8, -1, 2, -1, 4, -1, 1},
        {1, -26, 1},
        {28}
    };
    return ret;
}

InitDataSuperCoinsData GameController::getInitSuperCoinsData() {
    InitDataSuperCoinsData ret = {
        {2, 1}, {2, 26},
        {27, 1}, {27, 26}
    };
    return ret;
}

InitDataPorlatsData GameController::getInitPorlatsData() {
    InitDataPorlatsData ret = {
        {{8, -1}, {8, 28}}, {{8, 28}, {8, -1}},
        {{17, -1}, {17, 28}}, {{17, 28}, {17, -1}}
    };
    return ret;
}

void GameController::drawView() {
    this->_view->draw(
        this->_model->getGameStatus()
    );
}

void GameController::listenForClicks() {
    this->_model->listenForClicks();
}

void GameController::moveEntities() {
    this->_model->moveEntities();
}

GameController::GameController() {
    this->_timer = new Timer(TIME_UNIT);
    this->_model = new GameModel(
        this->getInitFieldsIsWall(), 
        this->getInitFieldsCoin(), 
        this->getInitSuperCoinsData(),
        this->getInitPorlatsData(),
        FIELDS_X,
        FIELDS_Y
    );
    this->_view = new GameView(this->_model->getBoardDataRef(), FIELD_SIZE);
}

void GameController::gameLoop() {
    this->drawView();
    this->listenForClicks();
    if (this->_timer->isDone()) {
        this->_timer->reset(TIME_UNIT - this->_timer->calcDelay());
        this->moveEntities();
    }
}