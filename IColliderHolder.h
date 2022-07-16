#pragma once

/** @brief コライダーを保持するオブジェクト用インターフェース */
class IColliderHolder {
public:
    /**
     * @brief 【仮想関数】ColliderHolderID のゲッター
     * @return ColliderHolderID
     */
    virtual ColliderID getColliderHolderID() = 0;

    /**
     * @brief 【仮想関数】描画座標（x軸）のゲッター
     * @return 描画座標（x軸）
     */
    virtual int getX() = 0;

    /**
     * @brief 【仮想関数】描画座標（y軸）のゲッター
     * @return 描画座標（y軸）
     */
    virtual int getY() = 0;

    /**
     * @brief 【仮想関数】描画座標（x軸）のセッター
     * @return 描画座標（x軸）
     */
    virtual void setX(int x) = 0;

    /**
     * @brief 【仮想関数】描画座標（y軸）のセッター
     * @return 描画座標（y軸）
     */
    virtual void setY(int y) = 0;
};