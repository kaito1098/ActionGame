#include "RectCollider.h"

RectCollider::RectCollider(IColliderHolder* holderPtr, int dx, int dy, int width, int height) :
    BaseCollider(holderPtr, dx, dy),
    m_width(width), m_height(height) {
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

bool RectCollider::checkFalling() {
    //TODOFŽÀÛ‚É‚Í‚Ç‚¤”»’è‚·‚×‚«‚©H
    return true;
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