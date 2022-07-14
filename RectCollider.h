#pragma once
#include "BaseCollider.h"

/** @brief 矩形の当たり判定クラス */
class RectCollider : public BaseCollider {
public:
    /** @brief 矩形同士の衝突判定 */
    bool isCollide(std::shared_ptr<RectCollider> target);
    
    /** @brief マップ地形との衝突判定 */
    bool isCollide() override;

private:
    /** @brief 矩形の横幅 */
    int width;

    /** @brief 矩形の縦幅 */
    int height;

    /** @brief 上辺のy座標 */
    int top();

    /** @brief 下辺のy座標 */
    int bottom();

    /** @brief 左辺のx座標 */
    int left();

    /** @brief 右辺のy座標 */
    int right();
};