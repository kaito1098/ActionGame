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
    std::array<int, 2> checkMapCollide() override;

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
     * @brief 床との当たり判定
     * @return true：落下している、false：落下していない
     */
    bool checkMapCollideFloor(std::shared_ptr<Map> mapPtr, int& x, int& y);

    /**
     * @brief 壁との当たり判定（右方向）
     * @return true：衝突している、false：衝突していない
     */
    bool checkMapCollideRight(std::shared_ptr<Map> mapPtr, int& x, int& y);

    /**
     * @brief 天井との当たり判定
     * @return true：衝突している、false：衝突していない
     */
    bool checkMapCollideCeiling(std::shared_ptr<Map> mapPtr, int& x, int& y);

    /**
     * @brief 壁との当たり判定（左方向）
     * @return true：衝突している、false：衝突していない
     */
    bool checkMapCollideLeft(std::shared_ptr<Map> mapPtr, int& x, int& y);

    /** @brief 上辺のy座標（ holder の位置を基準とする） */
    int top();

    /** @brief 下辺のy座標（ holder の位置を基準とする） */
    int bottom();

    /** @brief 左辺のx座標（ holder の位置を基準とする） */
    int left();

    /** @brief 右辺のy座標（ holder の位置を基準とする） */
    int right();

    /** @brief 上辺のy座標（指定座標を基準とする） */
    int top(int y);

    /** @brief 下辺のy座標（指定座標を基準とする） */
    int bottom(int y);

    /** @brief 左辺のx座標（指定座標を基準とする） */
    int left(int x);

    /** @brief 右辺のy座標（指定座標を基準とする） */
    int right(int x);
};