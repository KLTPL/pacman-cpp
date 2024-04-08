#include <iostream>
#include <raylib.h>
#include "Controller.h"
#include "utils.h"
#include "Timer.h"

int main () {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pacman");
    SetTargetFPS(60);
    std::cout << SCREEN_WIDTH << " " << SCREEN_HEIGHT << " " << FIELD_SIZE << "\n";
    GameController gameController = GameController();

    while (WindowShouldClose() == false){
        BeginDrawing();
        ClearBackground(BLACK);

        gameController.gameLoop();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}