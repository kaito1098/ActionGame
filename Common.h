#pragma once
#include <memory>
#include "GameManager.h"
#include "ColliderManager.h"

class GameManager;
class ColliderManager;

extern std::unique_ptr<GameManager> gameManagerPtr;
extern std::unique_ptr<ColliderManager> colliderManager;

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern const int COLLIDERS_TREE_LEVEL;

extern const int MAX_FALL_SPEED;

extern const int GROUND_HEIGHT;