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

GameView::GameView(BoardDataRefForView boardDataRef, int fieldSizePx) {
    this->_boardDataRef = boardDataRef;
    this->_fieldSizePx = fieldSizePx;
}

void GameView::draw(const GameStatusForView &gameStatus) {
    this->drawWalls();
    this->drawPacman(gameStatus);
    this->drawCoins();
}