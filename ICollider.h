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
     * @brief 【仮想関数】矩形コライダーとの当たり判定
     * @param (arg)
     * @return 戻り値の説明
     */
    virtual bool isCollide(std::shared_ptr<RectCollider> target) = 0;

    /**
     * @brief 【仮想関数】マップ地形との当たり判定
     * @param (arg)
     * @return 戻り値の説明
     */
    virtual bool isCollide() = 0;

    /**
     * @【仮想関数】brief 落下しているかどうか（着地しているかどうか）
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