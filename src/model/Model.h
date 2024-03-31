#ifndef MODEL_H
#define MODEL_H
#include <vector>
#include "./utils/modelTypes.h"
#include "../utils/pos.h"

class PacmanModel {
private:
    FieldsIsWall _fieldsIsWall;
    FieldsCoin _fieldsCoin;
    PorlatsData _portalsData;
    int _width = 0;
    int _height = 0;
    FieldsIsWall _getInitFieldsIsWallConverted(InitDataFieldsIsWall initFieldsIsWall);
    FieldsCoin _getInitFieldsCoinConverted(
        InitDataFieldsCoin initFieldsCoin, 
        InitDataSuperCoinsData initSuperCoinsData
    );
    PorlatsData _getInitPortalsDataConverted(InitDataPorlatsData initPortalsData);
public:
    PacmanModel(
        InitDataFieldsIsWall initFieldsIsWall, 
        InitDataFieldsCoin initFieldsCoin, 
        InitDataSuperCoinsData initSuperCoinsData, 
        InitDataPorlatsData initPortalsData, 
        int width, 
        int height
    );
    int getWidth();
    int getHeight();
};

#endif 