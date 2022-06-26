#pragma once
#include <memory>
#include "GameManager.h"

//・ゲーム全体の管理用オブジェクト
class GameManager;
extern std::unique_ptr<GameManager> gameManagerPtr;

//・画面解像度
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;