#pragma once


typedef struct PosInt {
  int y;
  int x;
} PosInt;

typedef struct PosDouble {
  double y;
  double x;
} PosDouble;

enum Dir {
  Forward = 1, Back = -1, Stop = 0
};
typedef struct Direction {
  Dir y;
  Dir x;
} Direction;