#include <iostream>
#include <vector>
#include "Model.h"
#include "modelTypes.h"


GameModel::GameModel(
    InitDataFieldsIsWall initFieldsIsWall, 
    InitDataFieldsCoin initFieldsCoin, 
    InitDataSuperCoinsData initSuperCoinsData, 
    InitDataPorlatsData initPortalsData, 
    int fieldsX, 
    int fieldsY
) {
    this->_fieldsIsWall = this->_getInitFieldsIsWallConverted(initFieldsIsWall);
    this->_fieldsCoin = this->_getInitFieldsCoinConverted(initFieldsCoin, initSuperCoinsData);
    this->_portalsData = this->_getInitPortalsDataConverted(initPortalsData);
    this->_fieldsX = fieldsX;
    this->_fieldsY = fieldsY;
    this->_pacman = new Pacman({23, 13.5}, {0, 0.2});
}

BoardDataRefForView GameModel::getBoardDataRef() {
    return {
        this->_fieldsX,
        this->_fieldsY,
        &this->_fieldsIsWall,
        &this->_fieldsCoin
    };
}
GameStatusForView GameModel::getGameStatus() {
    return {
        this->_pacman->getPos()
    };
}

FieldsIsWall GameModel::_getInitFieldsIsWallConverted(InitDataFieldsIsWall initFieldsIsWall) {
    FieldsIsWall ret;
    for (const auto &row : initFieldsIsWall) {
        std::vector<bool> newRow;
        for (const int &amount : row) {
            bool toSet = (amount > 0 ? true : false);
            for (int i = 0; i < abs(amount); i++) {
                newRow.push_back(toSet);
            }
        }
        ret.push_back(newRow);
    }
    return ret;
}

FieldsCoin GameModel::_getInitFieldsCoinConverted(
    InitDataFieldsCoin initFieldsCoin, 
    InitDataSuperCoinsData initSuperCoinsData
) {
    FieldsCoin ret;
    for (const auto &row : initFieldsCoin) {
        std::vector<Coins> newRow;
        for (const int &amount : row) {
            Coins toSet = (amount > 0 ? Coins::NoCoin : Coins::Base);
            for (int i = 0; i < abs(amount); i++) {
                newRow.push_back(toSet);
            }
        }
        ret.push_back(newRow);
    }

    // overwrite normal coins with better coins
    for (const auto &pos : initSuperCoinsData) {
        ret[pos.y][pos.x] = Coins::Super;
    }

    return ret;
}

PorlatsData GameModel::_getInitPortalsDataConverted(InitDataPorlatsData initPortalsData) {
    return initPortalsData;
}