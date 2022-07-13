#pragma once
#include "Common.h"

/** @brief コライダーを保持するオブジェクト用インターフェース */
class IColliderHolder {
public:
    /**
     * @brief ColliderHolderID のゲッター
     * @return ColliderHolderID
     */
    virtual ColliderID getColliderHolderID() = 0;

    /**
     * @brief 描画座標（x軸）のゲッター
     * @return 描画座標（x軸）
     */
    virtual int getX() = 0;

    /**
     * @brief 描画座標（y軸）のゲッター
     * @return 描画座標（y軸）
     */
    virtual int getY() = 0;
};