#pragma once

constexpr int 
    FIELDS_X = 28, 
    FIELDS_Y = 31,
    SCREEN_WIDTH = 560, 
    BOARD_HEIGHT = 620,
    BOTTOM_BAR_HEIGHT = 40,
    SCREEN_HEIGHT = BOARD_HEIGHT + BOTTOM_BAR_HEIGHT,
    FIELD_SIZE = SCREEN_WIDTH / FIELDS_X;

constexpr double
    TIME_UNIT = 0.125 / 5;
    