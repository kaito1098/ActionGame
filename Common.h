#pragma once
#include <memory>
#include "GameManager.h"

//・事前宣言
class GameManager;

//・TODO：ゲームマネージャクラスはシングルトンパターンで設計を見直す？
/** @brief ゲームマネージャ */
extern std::unique_ptr<GameManager> gameManagerPtr;

/** @brief 画面解像度（x軸方向） */
extern const int SCREEN_WIDTH;

/** @brief 画面解像度（y軸方向） */
extern const int SCREEN_HEIGHT;

/** @brief 最大落下速度 */
extern const int MAX_FALL_SPEED;

//・TODO：テスト用なのであとで消す
/** @brief 地面の高さ */
extern const int GROUND_HEIGHT;

/** @brief マップ当たり判定種別（列挙帯） */
enum class MapCollideID {
    passable = 0,
    impassable = 1,
    jumpPassable = 2,
    squatPassable = 3,
    rightStair = 4,
    leftStair = 5,
};

/** @brief 当たり判定種別（列挙帯） */
enum class ColliderID {
    Player = 0,
    Enemy = 1,
};