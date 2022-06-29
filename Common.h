#pragma once
#include <memory>
#include "GameManager.h"

class GameManager;
extern std::unique_ptr<GameManager> gameManagerPtr;

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

extern const int MAX_FALL_SPEED;

extern const int GROUND_HEIGHT;