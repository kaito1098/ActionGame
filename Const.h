#pragma once
#include <memory>

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
    passable = 0,       //・通行可能
    impassable = 1,     //・通行不可能
    jumpPassable = 2,   //・ジャンプで下から通行可能
    squatPassable = 3,  //・しゃがみＺで上から通行可能
    rightStair = 4,     //・右上がり階段
    leftStair = 5,      //・左上がり階段
};

/** @brief 当たり判定種別（列挙帯） */
enum class ColliderID {
    Player = 0,
    Enemy = 1,
};