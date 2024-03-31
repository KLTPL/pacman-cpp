#include <iostream>
#include <raylib.h>
#include "./src/controller/Controller.h"

constexpr int 
    SCREEN_WIDTH = 600, 
    SCREEN_HEIGHT = 660;

int main () {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "My first RAYLIB program!");
    SetTargetFPS(60);

    PacmanController *pacmanController = new PacmanController();

    while (WindowShouldClose() == false){
        BeginDrawing();
        ClearBackground(BLACK);


        EndDrawing();
    }

    CloseWindow();
    return 0;
}