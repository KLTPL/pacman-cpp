#include "Controller.h"
#include "controllerTypes.h"
#include "Model.h"
#include "View.h"
#include "Direction.h"

const InitDataFieldsIsWall GameController::_getInitFieldsIsWall() {
    const InitDataFieldsIsWall ret = { // positive - amount of walls, negative - amount of empty fields
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

const InitDataFieldsCoin GameController::_getInitFieldsCoin() {
    const InitDataFieldsCoin ret = {
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

const InitDataSuperCoinsData GameController::_getInitSuperCoinsData() {
    const InitDataSuperCoinsData ret = {
        {2, 1}, {2, 26},
        {27, 1}, {27, 26}
    };
    return ret;
}

const InitDataPortalsData GameController::_getInitPorlatsData() {
    const InitDataPortalsData ret = {
        {{8, -1}, {8, 28}}, {{8, 28}, {8, -1}},
        {{17, -1}, {17, 28}}, {{17, 28}, {17, -1}}
    };
    return ret;
}

const InitPacmanData GameController::_getInitPacmanData() {
    return {
        {23, 13.5}, 
        {Dir::Stop, Dir::Back}
    };
}

const PosDouble GameController::_getInitStartGhostPos() {
    return {11, 13};
}

const int GameController::_getInitGhostsAmount() {
    return 4;
}

void GameController::_drawView() {
    this->_view.draw(
        this->_model.getBoardDataRef()
    );
}

void GameController::_alternateEntitiesStateView() {
    this->_view.alternateEntityState();
}

void GameController::_listenForClicks() {
    this->_model._listenForClicks();
}

void GameController::_moveEntities() {
    this->_model._moveEntities();
}

GameController::GameController(ViewUnits viewUnits, double timeUnit): 
    _timeUnit(timeUnit),
    _timer(Timer(timeUnit)),
    _model(GameModel(
        this->_getInitFieldsIsWall(), 
        this->_getInitFieldsCoin(), 
        this->_getInitSuperCoinsData(),
        this->_getInitPorlatsData(),
        viewUnits.fieldsX,
        viewUnits.fieldsY,
        this->_getInitPacmanData(),
        this->_getInitStartGhostPos(),
        this->_getInitGhostsAmount()
    )),
    _view(GameView(viewUnits))
{}

void GameController::gameLoop() {
    this->_drawView();
    this->_listenForClicks();
    if (this->_timer.isDone()) {
        this->_timer.reset(this->_timeUnit - this->_timer.calcDelay());
        this->_moveEntities();
        this->_alternateEntitiesStateView();
    }
}