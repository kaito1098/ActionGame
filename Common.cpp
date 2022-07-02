#include "Common.h"

//・ゲーム全体の管理用クラス
std::unique_ptr<GameManager> gameManagerPtr = std::make_unique<GameManager>();

//・画面解像度
const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 900;

//・物理量の定義
const int MAX_FALL_SPEED = 8;

//・地面の高さ（TODO：テスト用なのであとで消す）
const int GROUND_HEIGHT = SCREEN_HEIGHT + 36;