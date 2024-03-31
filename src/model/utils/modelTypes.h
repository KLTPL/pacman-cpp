#ifndef MODEL_UTILS_H
#define MODEL_UTILS_H
#include <vector>
#include "../../utils/pos.h"

enum Coins {
    NoCoin, Base, Super
};

typedef struct PortalData {
    Pos from;
    Pos to;
} PortalData;

typedef std::vector<std::vector<bool>> FieldsIsWall;
typedef std::vector<std::vector<Coins>> FieldsCoin;
typedef std::vector<PortalData> PorlatsData;

typedef std::vector<std::vector<int>> InitDataFieldsIsWall; // positive number - walls (ex. 5 - five walls), negative number - empty fields
typedef std::vector<std::vector<int>> InitDataFieldsCoin; // positive number - no coin fields (ex. 5 - five no coin fields), negative number - coin fields
typedef std::vector<Pos> InitDataSuperCoinsData;
typedef PorlatsData InitDataPorlatsData;

#endif
