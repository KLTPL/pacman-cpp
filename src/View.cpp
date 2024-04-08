#include <iostream>
#include "View.h"
#include "raylib.h"

void GameView::drawWalls() {
    int fSize = this->_fieldSizePx;
    for (int r = 0; r < this->_boardDataRef.fieldsY; r++) {
        for (int c = 0; c < this->_boardDataRef.fieldsX; c++) {
            DrawRectangle(
                c * fSize, 
                r * fSize, 
                fSize, 
                fSize, 
                ((*this->_boardDataRef.fieldsIswall)[r][c] == true) ? BLUE : BLACK
            );
        }
    }
}
void GameView::drawPacman(const GameStatusForView &gameStatus) {
    int fSize = this->_fieldSizePx;
    double radius = fSize * 0.5;
    DrawCircle(
        gameStatus.pacmanPos.x * fSize + radius, 
        gameStatus.pacmanPos.y * fSize + radius,
        radius,
        YELLOW
    );
}
void GameView::drawCoins() {
    const int fSize = this->_fieldSizePx;
    const int radiusBase = fSize / 5;
    const int radiusBetter = fSize / 3;
    for (int r = 0; r < this->_boardDataRef.fieldsY; r++) {
        for (int c = 0; c < this->_boardDataRef.fieldsX; c++) {
            Coins coin = this->_boardDataRef.fieldsCoin->at(r).at(c);
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

void GameView::drawBottomBar() {
    const int fontSize = 15;
    std::string pointsStr = std::to_string(*this->_boardDataRef.playerPoints);
    auto pointsCStr = pointsStr.c_str();
    int textWidth = MeasureText(pointsCStr, fontSize);
    DrawText(
        pointsCStr, 
        (this->_screenWidth - textWidth) / 2,
        this->_boardHeight + ((this->_bottomBarHeight - fontSize) / 2),
        fontSize,
        WHITE
    );
}

GameView::GameView(BoardDataRefForView boardDataRef, const int fieldSizePx, const int screenWidth, const int boardHeight, const int bottomBarHeight) {
    this->_boardDataRef = boardDataRef;
    this->_fieldSizePx = fieldSizePx;
    this->_screenWidth = screenWidth;
    this->_boardHeight = boardHeight;
    this->_bottomBarHeight = bottomBarHeight;
}

void GameView::draw(const GameStatusForView &gameStatus) {
    this->drawWalls();
    this->drawPacman(gameStatus);
    this->drawCoins();
    this->drawBottomBar();
}