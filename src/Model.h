#pragma once

#include <vector>
#include "modelTypes.h"
#include "pos.h"
#include "Pacman.h"

class GameModel {
private:
    FieldsIsWall _fieldsIsWall;
    FieldsCoin _fieldsCoin;
    PortalsData _portalsData;
    int _fieldsX = 0;
    int _fieldsY = 0;
    Pacman *_pacman;
    int _playerPoints = 0;
    FieldsIsWall _getInitFieldsIsWallConverted(InitDataFieldsIsWall initFieldsIsWall);
    FieldsCoin _getInitFieldsCoinConverted(
        InitDataFieldsCoin initFieldsCoin, 
        InitDataSuperCoinsData initSuperCoinsData
    );
    PortalsData _getInitPortalsDataConverted(InitDataPortalsData initPortalsData);
    void movePacman();
    void collectCoinPacman();
public:
    GameModel(
        InitDataFieldsIsWall initFieldsIsWall, 
        InitDataFieldsCoin initFieldsCoin, 
        InitDataSuperCoinsData initSuperCoinsData, 
        InitDataPortalsData initPortalsData, 
        int fieldsX, 
        int fieldsY
    );
    BoardDataRefForView getBoardDataRef();
    void listenForClicks();
    void moveEntities();
    bool isPosIn(PosInt pos);
};
