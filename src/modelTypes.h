#pragma once

#include <vector>
#include "pos.h"
#include "Direction.h"

enum Coins {
    NoCoin, Base, Super
};

typedef struct PortalData {
    PosInt from;
    PosInt to;
} PortalData;

typedef std::vector<std::vector<bool>> FieldsIsWall;
typedef std::vector<std::vector<Coins>> FieldsCoin;
typedef std::vector<PortalData> PortalsData;

typedef std::vector<std::vector<int>> InitDataFieldsIsWall; // positive number - walls (ex. 5 - five walls), negative number - empty fields
typedef std::vector<std::vector<int>> InitDataFieldsCoin; // positive number - no coin fields (ex. 5 - five no coin fields), negative number - coin fields
typedef std::vector<PosInt> InitDataSuperCoinsData;
typedef PortalsData InitDataPortalsData;

typedef struct PacmanDataForView {
    PosDouble pos;
    Direction direction;
} PacmanDataForView;

typedef struct BoardDataRefForView {
    int fieldsX;
    int fieldsY;
    int playerPoints;
    FieldsIsWall fieldsIswall;
    FieldsCoin fieldsCoin;
    PacmanDataForView pacmanData;
} BoardDataRefForView;
