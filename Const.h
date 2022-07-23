#pragma once
#include <memory>

/** @brief デバッグフラグ（当たり判定の可視化など） */
extern const bool DEBUG_FLAG;

/** @brief 画面解像度（x軸方向） */
extern const int SCREEN_WIDTH;

/** @brief 画面解像度（y軸方向） */
extern const int SCREEN_HEIGHT;

/** @brief 重力による毎フレームの加速度 */
extern const int GRAVITY;

/** @brief 最大落下速度 */
extern const int MAX_FALL_SPEED;

//・TODO：テスト用なのであとで消す
/** @brief 地面の高さ */
extern const int GROUND_HEIGHT;

/** @brief マップ当たり判定種別（列挙帯） */
enum class MapCollideID {
    passable = 0,       //・通行可能
    impassable = 1,     //・通行不可能
    jumpPassable = 2,   //・ジャンプで下から通行可能
    rightStair = 3,     //・右上がり階段
    leftStair = 4,      //・左上がり階段
};

/** @brief 当たり判定種別（列挙帯） */
enum class ColliderID {
    Player = 0,
    Enemy = 1,
};