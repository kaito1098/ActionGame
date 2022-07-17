#pragma once
#include <memory>

class GameManager;
class IColliderHolder;
class RectCollider;

/** @brief 当たり判定の基底クラス */
class ICollider {
public:
    /**
     * @brief コンストラクタ
     * @param (holderPtr) 当たり判定を保持するオブジェクトのポインタ
     * @param (dx) 当たり判定を保持するオブジェクトからの相対座標（x軸方向）
     * @param (dy) 当たり判定を保持するオブジェクトからの相対座標（y軸方向）
     */
    ICollider(IColliderHolder* holderPtr, int dx, int dy);

    /**
     * @brief 【仮想関数】デストラクタ
     */
    virtual ~ICollider() = default;

    /**
     * @brief 【仮想関数】当たり判定の描画（デバッグ用）
     */
    virtual void draw() = 0;

    /**
     * @brief 【仮想関数】矩形コライダーとの当たり判定
     * @param (target) 相手の矩形コライダー
     * @return true：衝突している、false：衝突していない
     */
    virtual bool isCollide(std::shared_ptr<RectCollider> target) = 0;

    /**
     * @brief 【仮想関数】天井との当たり判定
     * @return true：衝突している、false：衝突していない
     */
    virtual bool isMapCollide() = 0;

    /**
     * @【仮想関数】brief 落下中かどうか
     * @return true：落下している、false：落下していない
     */
    virtual bool isFalling() = 0;
    
    /** @brief 当たり判定を保持するオブジェクトを指すポインタ */
    IColliderHolder* m_holderPtr;

protected:
    /** @brief 当たり判定を保持するオブジェクトからの相対座標（x軸方向） */
    int m_dx;

    /** @brief 当たり判定を保持するオブジェクトからの相対座標（y軸方向） */
    int m_dy;
};