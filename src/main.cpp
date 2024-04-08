#include <iostream>
#include <raylib.h>
#include "Controller.h"
#include "units.h"
#include "Timer.h"

int main () {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pacman");
    SetTargetFPS(60);
    std::cout << SCREEN_WIDTH << " " << SCREEN_HEIGHT << " " << FIELD_SIZE << "\n";
    ViewUnits viewUnits = {
        FIELD_SIZE,
        BOARD_HEIGHT,
        SCREEN_WIDTH,
        BOTTOM_BAR_HEIGHT,
        FIELDS_X,
        FIELDS_Y
    };
    GameController gameController = GameController(viewUnits, TIME_UNIT);

    while (WindowShouldClose() == false) {
        BeginDrawing();
        ClearBackground(BLACK);

        gameController.gameLoop();
        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}