#include "View.h"
#include "raylib.h"

GameView::GameView(BoardDataRefForView boardDataRef, int fieldSizePx) {
    this->_boardDataRef = boardDataRef;
    this->_fieldSizePx = fieldSizePx;
}

void GameView::draw(GameStatusForView gameStatus) {
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
    double radius = fSize * 0.5;
    DrawCircle(
        gameStatus.pacmanPos.x * fSize + radius, 
        gameStatus.pacmanPos.y * fSize + radius,
        radius,
        YELLOW
    );
}