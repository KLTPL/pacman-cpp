#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "../model/Model.h"
#include "../view/View.h"

class PacmanController {
private:
    PacmanView *_view;
    PacmanModel *_model;
    InitDataFieldsIsWall getInitFieldsIsWall();
    InitDataFieldsCoin getInitFieldsCoin();
    InitDataSuperCoinsData getInitSuperCoinsData();
    InitDataPorlatsData getInitPorlatsData();
public:
    PacmanController();

};

#endif 