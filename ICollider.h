#pragma once
#include <memory>
#include <array>

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
    ICollider(IColliderHolder* holderPtr, ColliderID id, int dx, int dy);

    /**
     * @brief 【仮想関数】デストラクタ
     */
    virtual ~ICollider() = default;

    /**
     * @brief 【仮想関数】当たり判定の描画（デバッグ用）
     * @param (screenX) スクリーン座標（x軸方向）
     * @param (screenY) スクリーン座標（y軸方向）
     */
    virtual void draw(int screenX, int screenY) = 0;

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
    virtual bool checkPassableOver(int x, int y) = 0;

    /**
     * @brief 【仮想関数】床との当たり判定
     * @return true：落下している、false：落下していない
     */
    virtual bool checkPassableUnder(int x, int y) = 0;

    /**
     * @brief 【仮想関数】壁との当たり判定（左方向）
     * @return true：衝突している、false：衝突していない
     */
    virtual bool checkPassableLeft(int x, int y) = 0;

    /**
     * @brief 【仮想関数】壁との当たり判定（右方向）
     * @return true：衝突している、false：衝突していない
     */
    virtual bool checkPassableRight(int x, int y) = 0;

    /**
     * @brief 【仮想関数】床に接するための y 座標の値を取得する
     * @return 床に接するための y 座標の値
     */
    virtual int getFloorY(int x, int y) = 0;
    
    /** @brief 当たり判定を保持するオブジェクトを指すポインタ */
    IColliderHolder* m_holderPtr;

protected:
    const ColliderID colliderID;

    /** @brief 当たり判定を保持するオブジェクトからの相対座標（x軸方向） */
    int m_dx;

    /** @brief 当たり判定を保持するオブジェクトからの相対座標（y軸方向） */
    int m_dy;
};