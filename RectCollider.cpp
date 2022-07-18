#include "Common.h"
#include "DxLib.h"

RectCollider::RectCollider(IColliderHolder* holderPtr, ColliderID id, int dx, int dy, int width, int height) :
    ICollider(holderPtr, id, dx, dy),
    m_width(width), m_height(height) {
}

void RectCollider::draw() {
    if (!DEBUG_FLAG) return;
    const int color = GetColor(255, 0, 0);
    DrawLine(left(), top(), right(), top(), color);         //・上辺
    DrawLine(right(), top(), right(), bottom(), color);     //・右辺
    DrawLine(left(), bottom(), right(), bottom(), color);   //・下辺
    DrawLine(left(), top(), left(), bottom(), color);       //・左辺
}

bool RectCollider::isCollide(std::shared_ptr<RectCollider> target) {
    if (target->top() >= bottom() && target->bottom() <= top() &&
        target->left() >= right() && target->right() <= left()) {
        return true;
    }
    return false;
}

bool RectCollider::checkPassableOver(int x, int y) {
    std::shared_ptr<Map> mapPtr = gameManagerPtr->getMapPtr();
    //・コライダー領域の 1 ピクセル上が通行可能か？を判定する
    bool leftCheck = mapPtr->checkPassable(left(), top() - 1);
    bool rightCheck = mapPtr->checkPassable(right(), top() - 1);
    return leftCheck && rightCheck;
}

bool RectCollider::checkPassableUnder(int x, int y) {
    std::shared_ptr<Map> mapPtr = gameManagerPtr->getMapPtr();
    //・コライダー領域の 1 ピクセル下が通行可能か？を判定する
    bool leftCheck = mapPtr->checkPassable(left(), bottom() + 1);
    bool rightCheck = mapPtr->checkPassable(right(), bottom() + 1);
    return leftCheck && rightCheck;
}

bool RectCollider::checkPassableLeft(int x, int y) {
    std::shared_ptr<Map> mapPtr = gameManagerPtr->getMapPtr();
    //・コライダー領域の 1 ピクセル右が通行可能か？を判定する
    bool topCheck = mapPtr->checkPassable(left() - 1, top());
    bool bottomCheck = mapPtr->checkPassable(left() - 1, bottom());
    return topCheck && bottomCheck;
}

bool RectCollider::checkPassableRight(int x, int y) {
    std::shared_ptr<Map> mapPtr = gameManagerPtr->getMapPtr();
    //・コライダー領域の 1 ピクセル右が通行可能か？を判定する
    bool topCheck = mapPtr->checkPassable(right() + 1, top());
    bool bottomCheck = mapPtr->checkPassable(right() + 1, bottom());
    return topCheck && bottomCheck;
}

int RectCollider::top() {
    return m_holderPtr->getY() + m_dy;
}

int RectCollider::bottom() {
    return top() + m_height;
}

int RectCollider::left() {
    return m_holderPtr->getX() + m_dx;
}

int RectCollider::right() {
    return left() + m_width;
}