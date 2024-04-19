#include <iostream>
#include <vector>
#include <cmath>
#include "Model.h"
#include "modelTypes.h"


GameModel::GameModel(
    InitDataFieldsIsWall initFieldsIsWall, 
    InitDataFieldsCoin initFieldsCoin, 
    InitDataSuperCoinsData initSuperCoinsData, 
    InitDataPortalsData initPortalsData, 
    int fieldsX, 
    int fieldsY
): 
    _fieldsIsWall(this->_getInitFieldsIsWallConverted(initFieldsIsWall)),
    _fieldsCoin(this->_getInitFieldsCoinConverted(initFieldsCoin, initSuperCoinsData)),
    _portalsData(this->_getInitPortalsDataConverted(initPortalsData)),
    _fieldsX(fieldsX),
    _fieldsY(fieldsY),
    _pacman(Pacman({23, 13.5}, {Dir::Stop, Dir::Back}))
{}

BoardDataRefForView GameModel::getBoardDataRef() {
    return {
        this->_fieldsX,
        this->_fieldsY,
        this->_playerPoints,
        this->_fieldsIsWall,
        this->_fieldsCoin,
        {
            this->_pacman.getPos(),
            this->_pacman.getDirection()
        }
    };
}

void GameModel::listenForClicks() {
    this->_pacman.listenForClicks();
}

void GameModel::moveEntities() {
    this->movePacman();
    this->collectCoinPacman();
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

PortalsData GameModel::_getInitPortalsDataConverted(InitDataPortalsData initPortalsData) {
    return initPortalsData;
}

void GameModel::movePacman() {
    Pacman* p = &this->_pacman;
    bool isInCenter = p->isInFieldCenter();
    if (p->isNextDirTurningBack() && !isInCenter) {
        p->updateDirection();
    } else if (isInCenter) {
        PosInt nextForNextDir = p->calcNextPos(false);
        if (!this->_fieldsIsWall[nextForNextDir.y][nextForNextDir.x]) {
            p->updateDirection();
        }
        PosInt next = p->calcNextPos(true);
        if (!this->isPosIn(next) || this->_fieldsIsWall[next.y][next.x]) {
            p->setDirection(
                {Dir::Stop, Dir::Stop}
            );
        }
    }
    if (!p->isStopped()) {
        p->move();
    }
}

void GameModel::collectCoinPacman() {
    auto pPos = this->_pacman.getPos();
    if (this->_fieldsCoin[round(pPos.y)][round(pPos.x)] != Coins::NoCoin) {
        this->_playerPoints++;
        this->_fieldsCoin[round(pPos.y)][round(pPos.x)] = Coins::NoCoin;
    }
    if ( // if in the middle between two fields also check the other field
        !this->_pacman.isInFieldCenter() &&
        (
            (pPos.x != int(pPos.x) && ((int(pPos.x * 10) % 5) == 0)) ||
            (pPos.y != int(pPos.y) && ((int(pPos.y * 10) % 5) == 0)) 
        )
    ) {
        if (this->_fieldsCoin[int(pPos.y)][int(pPos.x)] != Coins::NoCoin) {
            this->_playerPoints++;
            this->_fieldsCoin[int(pPos.y)][int(pPos.x)] = Coins::NoCoin;
        }
    }
}

bool GameModel::isPosIn(PosInt pos) {
    return (
        pos.y >= 0 && pos.y < this->_fieldsY &&
        pos.x >= 0 && pos.x < this->_fieldsX
    );
}
