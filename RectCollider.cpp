#include "RectCollider.h"

bool RectCollider::isCollide(std::shared_ptr<RectCollider> target) {
    //・矩形同士の衝突判定
    if (target->top >= bottom && target->bottom <= top &&
        target->left >= right && target->right <= left) {
        return true;
    }
    return false;
}

void RectCollider::pushCollidersTree() {
    //・所属する空間を計算して四分木に自身を登録する

}