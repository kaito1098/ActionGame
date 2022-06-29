#include "Common.h"

//・ゲーム全体の管理用クラス
std::unique_ptr<GameManager> gameManagerPtr = std::make_unique<GameManager>();

//・画面解像度
const int SCREEN_WIDTH = 854;
const int SCREEN_HEIGHT = 480;

//・物理量の定義
const int MAX_FALL_SPEED = 8;