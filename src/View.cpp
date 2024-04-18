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
    int fSize = this->_units.fieldSizePx;
    double radius = fSize * 0.5;
    DrawCircle(
        boardDataRef.pacmanPos.x * fSize + radius, 
        boardDataRef.pacmanPos.y * fSize + radius,
        radius,
        YELLOW
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
    _units(units) 
{}

void GameView::draw(const BoardDataRefForView &boardDataRef) {
    this->drawWalls(boardDataRef);
    this->drawPacman(boardDataRef);
    this->drawCoins(boardDataRef);
    this->drawBottomBar(boardDataRef);
}