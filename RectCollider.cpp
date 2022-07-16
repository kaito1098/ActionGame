#include "Common.h"
#include "DxLib.h"

RectCollider::RectCollider(IColliderHolder* holderPtr, int dx, int dy, int width, int height) :
    ICollider(holderPtr, dx, dy),
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

bool RectCollider::isCollide() {
    if (false) {
        return true;
    }
    return false;
}

bool RectCollider::isFalling() {
    std::shared_ptr<Map> mapPtr = gameManagerPtr->getMapPtr();
    //・コライダー領域の 1 ピクセル下が通行可能か？を判定する
    bool leftCheck = mapPtr->getMapCollideID(left(), bottom() + 1) == MapCollideID::passable;
    bool rightCheck = mapPtr->getMapCollideID(right(), bottom() + 1) == MapCollideID::passable;
    if (leftCheck && rightCheck) {
        return true;
    } else {
        int over = 0;   //・めり込んだピクセル量
        while (mapPtr->getMapCollideID(leftCheck ? right() : left(), bottom() - over) != MapCollideID::passable) {
            over++;
        }
        m_holderPtr->setY(m_holderPtr->getY() - over);
        return false;
    }
}

int RectCollider::top() {
    return this->m_holderPtr->getY() + this->m_dy;
}

int RectCollider::bottom() {
    return top() + this->m_height;
}

int RectCollider::left() {
    return this->m_holderPtr->getX() + this->m_dx;
}

int RectCollider::right() {
    return left() + this->m_width;
}