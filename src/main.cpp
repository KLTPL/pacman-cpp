#include <iostream>
#include <raylib.h>
#include "Controller.h"
#include "utils.h"
#include "Timer.h"

int main () {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Pacman");
    SetTargetFPS(60);

    GameController gameController = GameController();
    Timer timer = Timer(TIME_UNIT);

    while (WindowShouldClose() == false){
        BeginDrawing();
        ClearBackground(BLACK);

        gameController.drawView();
        gameController.listenForClicks();
        if (timer.isDone()) {
            timer.reset(TIME_UNIT - timer.calcDelay());
            gameController.moveEntities();
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}