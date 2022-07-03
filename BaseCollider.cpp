#include "BaseCollider.h"

BaseCollider::BaseCollider(std::shared_ptr<BaseActor> _holderPtr) :
    holderPtr(_holderPtr)
{
}

void BaseCollider::hit(std::shared_ptr<BaseActor> object) {
    holderPtr->hit();
}

unsigned long BaseCollider::getNodeIndexForRect(int left, int top, int right, int bottom) {
    unsigned long leftTop = getNodeIndexForPoint(left, top);
    unsigned long rightBottom = getNodeIndexForPoint(right, bottom);
    unsigned long temp = leftTop ^ rightBottom;
    unsigned long mask = 0xFFFFFFFF;
    for (int i = 2; i <= 32; i += 2) {
        mask = mask >> 2;
        if ((temp & !mask) > 0) temp = temp >> (32 - i);
    }
    return temp;
}

unsigned long BaseCollider::getNodeIndexForPoint(int x, int y) {
    unsigned long normalX = (unsigned long)(x / SCREEN_WIDTH / pow(2, COLLIDERS_TREE_LEVEL));
    unsigned long normalY = (unsigned long)(y / SCREEN_HEIGHT / pow(2, COLLIDERS_TREE_LEVEL));
    //・ビット分割
    auto separate = [](unsigned long n) {
        n = (n | n << 8) & 0x00FF00FF;
        n = (n | n << 4) & 0x0F0F0F0F;
        n = (n | n << 2) & 0x33333333;
        n = (n | n << 1) & 0x55555555;
        return n;
    };
    //・モートン番号に空間レベルの添え字を考慮してインデックスを返却
    return (unsigned long)((separate(normalX) | (separate(normalY) << 1)) + pow(4, COLLIDERS_TREE_LEVEL) - 1 / 3);
}