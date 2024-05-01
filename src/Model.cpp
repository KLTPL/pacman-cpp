#include <iostream>
#include <vector>
#include <cmath>
#include <memory>
#include <queue>
#include <algorithm>
#include "Model.h"
#include "modelTypes.h"
#include "controllerTypes.h"
#include "Ghost.h"


GameModel::GameModel(
    InitDataFieldsIsWall initFieldsIsWall, 
    InitDataFieldsCoin initFieldsCoin, 
    InitDataSuperCoinsData initSuperCoinsData, 
    InitDataPortalsData initPortalsData, 
    int fieldsX, 
    int fieldsY,
    InitPacmanData initPacmanData,
    PosDouble ghostStartPos,
    int initGhostsAmount
): 
    _fieldsIsWall(this->_getInitFieldsIsWallConverted(initFieldsIsWall)),
    _fieldsCoin(this->_getInitFieldsCoinConverted(initFieldsCoin, initSuperCoinsData)),
    _portalsData(this->_getInitPortalsDataConverted(initPortalsData)),
    _fieldsX(fieldsX),
    _fieldsY(fieldsY),
    _pacman(Pacman(initPacmanData.pos, initPacmanData.direction)),
    _ghostStartPos(ghostStartPos),
    _ghosts({})
{
    _ghosts.push_back(Ghost(ghostStartPos, this->_calcNewPathForGhost(ghostStartPos)));
}

BoardDataRefForView GameModel::getBoardDataRef() {
    std::vector<PosDouble> ghostsPos;
    for (auto ghost : this->_ghosts) {
        ghostsPos.push_back(ghost.getPos());
    }

    return {
        this->_fieldsX,
        this->_fieldsY,
        this->_playerPoints,
        this->_fieldsIsWall,
        this->_fieldsCoin,
        {
            this->_pacman.getPos(),
            this->_pacman.getDirection()
        },
        ghostsPos
    };
}

void GameModel::listenForClicks() {
    this->_pacman.listenForClicks();
}

void GameModel::moveEntities() {
    this->_movePacman();
    this->_collectCoinPacman();
    this->_moveGhosts();
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

void GameModel::_movePacman() {
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

std::vector<PosInt> GameModel::_calcNewPathForGhost(PosDouble ghostPos) {
    PosInt ghostPosInt = {int(ghostPos.y), int(ghostPos.x)};
    PosInt endPos = this->_genGoToPosAroundPacmanForGhost(0);
    VisitedFields visited;
    visited.resize(this->_fieldsY);
    for (int r = 0; r < this->_fieldsY; r++) {
        visited[r].resize(this->_fieldsX);
        for (int c = 0; c < this->_fieldsX; c++) {
            visited[r][c] = nullptr;
        }
    }
    
    this->_exploreGraphBFS(visited, ghostPosInt, endPos);

    if (visited[endPos.y][endPos.x] == nullptr) {
        std::cout << "ERROR: Path to given position not found\n";
        return {};
    }

    auto path = this->_findPathFromVisited(visited, ghostPosInt, endPos);
    for (int r = 0; r < this->_fieldsY; r++) {
        for (int c = 0; c < this->_fieldsX; c++) {
            if (visited[r][c] != nullptr) {
                delete visited[r][c];
            }
        }
    }
    return path;
}

std::vector<PosInt> GameModel::_findPathFromVisited( // backtrack to startPos
    VisitedFields visited, 
    PosInt startPos, 
    PosInt endPos
) {
    std::vector<PosInt> path;
    auto currPos = endPos;
    while (currPos.x != startPos.x || currPos.y != startPos.y) {
        path.push_back(currPos);
        currPos = *visited[currPos.y][currPos.x];
    }
    std::reverse(path.begin(), path.end());
    return path;
}

void GameModel::_exploreGraphBFS(
    VisitedFields &visited, 
    PosInt startPos, 
    PosInt endPos
) {
    std::queue<PosInt> q;

    q.push(startPos);
    visited[startPos.y][startPos.x] = new PosInt({startPos.y, startPos.x});

    while (!q.empty()) {
        auto currPos = q.front();
        q.pop();

        for (const auto &neighbourPos : this->_getNeighbourFields(currPos)) {
            if (!visited[neighbourPos.y][neighbourPos.x]) {
                visited[neighbourPos.y][neighbourPos.x] = new PosInt({currPos.y, currPos.x});
                if (endPos.y == neighbourPos.y && endPos.x == neighbourPos.x) {
                    return;
                }
                q.push(neighbourPos);
            }
        }
    }
}

std::vector<PosInt> GameModel::_getNeighbourFields(PosInt pos) { // return fields that are in the board and are not walls
    std::vector<PosInt> ret;
    const std::vector<Direction> directions = {
        {Dir::Forward, Dir::Stop},
        {Dir::Back, Dir::Stop},
        {Dir::Stop, Dir::Forward},
        {Dir::Stop, Dir::Back},
    };
    for (auto direction : directions) {
        PosInt newPos = {pos.y + direction.y(), pos.x + direction.x()};
        if (
            this->isPosIn(newPos) &&
            !this->_fieldsIsWall[newPos.y][newPos.x]
        ) {
            ret.push_back(newPos);
        }
    }
    return ret;
}

PosInt GameModel::_genGoToPosAroundPacmanForGhost(double radius) {
    auto pPos = this->_pacman.getPos();
    auto minY = pPos.y - radius < 0 ? 0 : pPos.y - radius;
    auto maxY = pPos.y + radius >= this->_fieldsY ? 0 : pPos.y + radius;
    auto minX = pPos.x - radius < 0 ? 0 : pPos.x - radius;
    auto maxX = pPos.x + radius >= this->_fieldsX ? 0 : pPos.x + radius;

    PosInt pos;
    do {
        int rangeY = int(round((maxY - minY + 1)));
        int rangeX = int(round((maxX - minX + 1)));
        pos = {
            int(round(minY) + (std::rand() % rangeY)), // random number in range
            int(round(minX) + (std::rand() % rangeX))
        };
    } while (this->_fieldsIsWall[pos.y][pos.x]);

    return pos;
}

void GameModel::_collectCoinPacman() {
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

void GameModel::_moveGhosts() {
    for (auto &ghost : this->_ghosts) {
        ghost.move();
        if (ghost.isInFieldCenter()) {
            if (ghost.isPathEmpty()) {
                ghost.setPath(
                    this->_calcNewPathForGhost(ghost.getPos())
                );
            }
            ghost.updateDirectionFromCurrPath();
        }
    }
}

bool GameModel::isPosIn(PosInt pos) {
    return (
        pos.y >= 0 && pos.y < this->_fieldsY &&
        pos.x >= 0 && pos.x < this->_fieldsX
    );
}
