#pragma once
#include "ICollider.h"

/** @brief 矩形の当たり判定クラス */
class RectCollider : public ICollider {
public:
    /**
     * @brief コンストラクタ
     * @param (IColliderHolderPtr) 当たり判定を保持するオブジェクトを指すポインタ
     */
    RectCollider(IColliderHolder* holderPtr, ColliderID id, int dx, int dy, int width, int height);

    /**
     * @brief 当たり判定の描画（デバッグ用）
     * @param (screenX) スクリーン座標（x軸方向）
     * @param (screenY) スクリーン座標（y軸方向）
     */
    void draw(int screenX, int screenY) override;

    /**
     * @brief 矩形コライダーとの当たり判定
     * @param (target) 相手の矩形コライダー
     * @return true：衝突している、false：衝突していない
     */
    bool isCollide(std::shared_ptr<RectCollider> target) override;

    /**
     * @brief 天井との当たり判定
     * @return true：衝突している、false：衝突していない
     */
    bool checkPassableOver(int x, int y) override;

    /**
     * @brief 床との当たり判定
     * @return true：落下している、false：落下していない
     */
    bool checkPassableUnder(int x, int y) override;

    /**
     * @brief 壁との当たり判定（左方向）
     * @return true：衝突している、false：衝突していない
     */
    bool checkPassableLeft(int x, int y) override;

    /**
     * @brief 壁との当たり判定（右方向）
     * @return true：衝突している、false：衝突していない
     */
    bool checkPassableRight(int x, int y) override;

    /**
     * @brief 床に接するための y 座標の値を取得する
     * @return 床に接するための y 座標の値
     */
    int getFloorY(int x, int y) override;

private:
    /** @brief 矩形の横幅 */
    int m_width;

    /** @brief 矩形の縦幅 */
    int m_height;

    /** @brief 上辺のy座標（ holder の位置を基準とする） */
    int top();

    /** @brief 下辺のy座標（ holder の位置を基準とする） */
    int bottom();

    /** @brief 左辺のx座標（ holder の位置を基準とする） */
    int left();

    /** @brief 右辺のy座標（ holder の位置を基準とする） */
    int right();

    /** @brief 上辺のy座標（指定の位置を基準とする） */
    int top(int y);

    /** @brief 下辺のy座標（指定の位置を基準とする） */
    int bottom(int y);

    /** @brief 左辺のx座標（指定の位置を基準とする） */
    int left(int x);

    /** @brief 右辺のy座標（指定の位置を基準とする） */
    int right(int x);
};