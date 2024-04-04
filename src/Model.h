#pragma once

#include <vector>
#include "modelTypes.h"
#include "pos.h"
#include "Pacman.h"

class GameModel {
private:
    FieldsIsWall _fieldsIsWall;
    FieldsCoin _fieldsCoin;
    PorlatsData _portalsData;
    int _fieldsX = 0;
    int _fieldsY = 0;
    Pacman *_pacman;
    FieldsIsWall _getInitFieldsIsWallConverted(InitDataFieldsIsWall initFieldsIsWall);
    FieldsCoin _getInitFieldsCoinConverted(
        InitDataFieldsCoin initFieldsCoin, 
        InitDataSuperCoinsData initSuperCoinsData
    );
    PorlatsData _getInitPortalsDataConverted(InitDataPorlatsData initPortalsData);
    void movePacman();
public:
    GameModel(
        InitDataFieldsIsWall initFieldsIsWall, 
        InitDataFieldsCoin initFieldsCoin, 
        InitDataSuperCoinsData initSuperCoinsData, 
        InitDataPorlatsData initPortalsData, 
        int fieldsX, 
        int fieldsY
    );
    BoardDataRefForView getBoardDataRef();
    GameStatusForView getGameStatus();
    void listenForClicks();
    void moveEntities();
    bool isPosIn(PosInt pos);
};
