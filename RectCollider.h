#pragma once
#include "ICollider.h"

/** @brief 矩形の当たり判定クラス */
class RectCollider : public ICollider {
public:
    /**
     * @brief コンストラクタ
     * @param (IColliderHolderPtr) 当たり判定を保持するオブジェクトを指すポインタ
     */
    RectCollider(IColliderHolder* holderPtr, int dx, int dy, int width, int height);

    /**
     * @brief 当たり判定の描画（デバッグ用）
     */
    void draw() override;

    /**
     * @brief 矩形コライダーとの当たり判定
     * @param (target) 相手の矩形コライダー
     * @return true：衝突している、false：衝突していない
     */
    bool isCollide(std::shared_ptr<RectCollider> target) override;

    /**
     * @brief マップ地形との当たり判定
     * @return true：衝突している、false：衝突していない
     */
    bool isMapCollide() override;

    /**
     * @【仮想関数】brief 落下中かどうか
     * @return true：落下している、false：落下していない
     */
    bool isFalling() override;

private:
    /** @brief 矩形の横幅 */
    int m_width;

    /** @brief 矩形の縦幅 */
    int m_height;

    /**
     * @brief 天井との当たり判定
     * @return true：衝突している、false：衝突していない
     */
    bool isMapCollideCeiling(std::shared_ptr<Map> mapPtr);

    /**
     * @brief 壁との当たり判定（右方向）
     * @return true：衝突している、false：衝突していない
     */
    bool isMapCollideRight(std::shared_ptr<Map> mapPtr);

    /**
     * @brief 壁との当たり判定（左方向）
     * @return true：衝突している、false：衝突していない
     */
    bool isMapCollideLeft(std::shared_ptr<Map> mapPtr);

    /**
     * @brief 床との当たり判定
     * @return true：落下している、false：落下していない
     */
    bool isMapCollideFloor(std::shared_ptr<Map> mapPtr);

    /** @brief 上辺のy座標 */
    int top();

    /** @brief 下辺のy座標 */
    int bottom();

    /** @brief 左辺のx座標 */
    int left();

    /** @brief 右辺のy座標 */
    int right();
};