#pragma once
#include "raylib.h"

constexpr float 
  PACMAN_IMAGE_WIDTH = 20, 
  PACMAN_IMAGE_HEIGHT = 20;

typedef struct PacmanImageData {
  Texture2D texture;
  float imageWidth;
  float imageHeight;
  Rectangle sourceRec1; // pacman mouth closed
  Rectangle sourceRec2; // pacman mouth opened
} PacmanImageData;