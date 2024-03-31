// #include "./Model.h";
#include <iostream>
#include <vector>
#include "./Model.h";
#include "./utils/modelTypes.h";


PacmanModel::PacmanModel(
    InitDataFieldsIsWall initFieldsIsWall, 
    InitDataFieldsCoin initFieldsCoin, 
    InitDataSuperCoinsData initSuperCoinsData, 
    InitDataPorlatsData initPortalsData, 
    int width, 
    int height
) {
    this->_fieldsIsWall = this->_getInitFieldsIsWallConverted(initFieldsIsWall);
    this->_fieldsCoin = this->_getInitFieldsCoinConverted(initFieldsCoin, initSuperCoinsData);
    this->_portalsData = this->_getInitPortalsDataConverted(initPortalsData);
    this->_width = width;
    this->_height = height;
}

int PacmanModel::getWidth() {
    return _width;
}

int PacmanModel::getHeight() {
    return _height;
}

FieldsIsWall PacmanModel::_getInitFieldsIsWallConverted(InitDataFieldsIsWall initFieldsIsWall) {
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

FieldsCoin PacmanModel::_getInitFieldsCoinConverted(
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

PorlatsData PacmanModel::_getInitPortalsDataConverted(InitDataPorlatsData initPortalsData) {
    return initPortalsData;
}