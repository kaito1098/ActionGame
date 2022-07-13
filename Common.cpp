#include "Common.h"

std::unique_ptr<GameManager> gameManagerPtr = std::make_unique<GameManager>();

const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 900;

const int MAX_FALL_SPEED = 8;

const int GROUND_HEIGHT = SCREEN_HEIGHT - 40;

enum class MapCollideID {
    passable = 0,
    impassable = 1,
    jumpPassable = 2,
    squatPassable = 3,
    rightStair = 4,
    leftStair = 5,
};