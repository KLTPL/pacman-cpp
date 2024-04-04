#include <iostream>
#include <raylib.h>
#include "Controller.h"
#include "utils.h"

int main () {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pacman");
    SetTargetFPS(60);

    GameController gameController = GameController();

    while (WindowShouldClose() == false){
        BeginDrawing();
        ClearBackground(BLACK);

        gameController.drawView();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}