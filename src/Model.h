#pragma once

#include <vector>
#include <memory>
#include "modelTypes.h"
#include "pos.h"
#include "Pacman.h"
#include "Ghost.h"

typedef std::vector<std::vector<PosInt*>> VisitedFields;

class GameModel {
private:
    FieldsIsWall _fieldsIsWall;
    FieldsCoin _fieldsCoin;
    PortalsData _portalsData;
    int _fieldsX = 0;
    int _fieldsY = 0;
    Pacman _pacman;
    int _playerPoints = 0;
    PosDouble _ghostStartPos;
    std::vector<Ghost> _ghosts;
    FieldsIsWall _getInitFieldsIsWallConverted(InitDataFieldsIsWall initFieldsIsWall);
    FieldsCoin _getInitFieldsCoinConverted(
        InitDataFieldsCoin initFieldsCoin, 
        InitDataSuperCoinsData initSuperCoinsData
    );
    PortalsData _getInitPortalsDataConverted(InitDataPortalsData initPortalsData);
    
    std::vector<PosInt> _calcNewPathForGhost(PosDouble ghostPos);
    void _exploreGraphBFS( // endPos must be found
        VisitedFields &visited, 
        PosInt startPos, 
        PosInt endPos
    );
    std::vector<PosInt> _findPathFromVisited(
        VisitedFields visited, 
        PosInt startPos, 
        PosInt endPos
    );
    std::vector<PosInt> _getNeighbourFields(PosInt pos);
    PosInt _genGoToPosAroundPacmanForGhost(double radius);
    void _movePacman();
    void _collectCoinPacman();
    void _moveGhosts();
public:
    GameModel(
        InitDataFieldsIsWall initFieldsIsWall, 
        InitDataFieldsCoin initFieldsCoin, 
        InitDataSuperCoinsData initSuperCoinsData, 
        InitDataPortalsData initPortalsData, 
        int fieldsX, 
        int fieldsY,
        InitPacmanData initPacmanData,
        PosDouble ghostStartPos,
        int initGhostsAmount
    );
    BoardDataRefForView getBoardDataRef();
    void _listenForClicks();
    void _moveEntities();
    bool isPosIn(PosInt pos);
};
