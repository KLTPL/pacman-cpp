#include <iostream>
#include "View.h"
#include "raylib.h"

void GameView::drawWalls(const BoardDataRefForView &boardDataRef) {
    int fSize = this->_units.fieldSizePx;
    for (int r = 0; r < boardDataRef.fieldsY; r++) {
        for (int c = 0; c < boardDataRef.fieldsX; c++) {
            DrawRectangle(
                c * fSize, 
                r * fSize, 
                fSize, 
                fSize, 
                ((boardDataRef.fieldsIswall)[r][c] == true) ? BLUE : BLACK
            );
        }
    }
}
void GameView::drawPacman(const BoardDataRefForView &boardDataRef) {
    auto pImg = this->_pacmanImageData;
    auto pData = boardDataRef.pacmanData;
    auto w = pImg.imageWidth;
    auto h = pImg.imageHeight;
    Rectangle dest = {
        float(pData.pos.x * this->_units.fieldSizePx + (w / 2)), 
        float(pData.pos.y * this->_units.fieldSizePx + (h / 2)), 
        w, 
        h
    };
    float rotation = 0;
    if (this->isEntityState1 || pData.direction.x == Dir::Forward) {
        rotation = 0;
    } else if (pData.direction.x == Dir::Back) {
        rotation = 180;
    } else if (pData.direction.y == Dir::Forward) {
        rotation = 90;
    } else if (pData.direction.y == Dir::Back) {
        rotation = 270;
    }
    bool isPacmanStopped = pData.direction.x == Dir::Stop && pData.direction.y == Dir::Stop;
    DrawTexturePro(
        pImg.texture, 
        (this->isEntityState1 || isPacmanStopped ? pImg.sourceRec1 : pImg.sourceRec2), 
        dest,
        {w / 2, h / 2},
        rotation, 
        WHITE
    );
}
void GameView::drawCoins(const BoardDataRefForView &boardDataRef) {
    const int fSize = this->_units.fieldSizePx;
    const int radiusBase = fSize / 5;
    const int radiusBetter = fSize / 3;
    for (int r = 0; r < boardDataRef.fieldsY; r++) {
        for (int c = 0; c < boardDataRef.fieldsX; c++) {
            Coins coin = boardDataRef.fieldsCoin.at(r).at(c);
            if (coin != Coins::NoCoin) {
                const int currRad = coin == Coins::Base ? radiusBase : radiusBetter;
                DrawCircle(
                    c * fSize + (fSize / 2), 
                    r * fSize + (fSize / 2), 
                    currRad,
                    YELLOW
                );
            }
        }
    }
};

void GameView::drawBottomBar(const BoardDataRefForView &boardDataRef) {
    const int fontSize = 15;
    std::string pointsStr = std::to_string(boardDataRef.playerPoints);
    auto pointsCStr = pointsStr.c_str();
    int textWidth = MeasureText(pointsCStr, fontSize);
    DrawText(
        pointsCStr, 
        (this->_units.screenWidth - textWidth) / 2,
        this->_units.boardHeight + ((this->_units.bottomBarHeight - fontSize) / 2),
        fontSize,
        WHITE
    );
}

GameView::GameView(ViewUnits units): 
    _units(units),
    _pacmanImageData({
        LoadTexture("./assets/pacman.png"),
        PACMAN_IMAGE_WIDTH,
        PACMAN_IMAGE_HEIGHT,
        { PACMAN_IMAGE_WIDTH + 1, 0, PACMAN_IMAGE_WIDTH, PACMAN_IMAGE_HEIGHT },
        { 0, 0, PACMAN_IMAGE_WIDTH, PACMAN_IMAGE_HEIGHT }
    }) {}

void GameView::draw(const BoardDataRefForView &boardDataRef) {
    this->drawWalls(boardDataRef);
    this->drawPacman(boardDataRef);
    this->drawCoins(boardDataRef);
    this->drawBottomBar(boardDataRef);
}

void GameView::alternateEntityState() {
    this->_gameTickCount++;
    if (this->_gameTickCount % 10 == 0) {
        this->isEntityState1 = !this->isEntityState1;
    }
}