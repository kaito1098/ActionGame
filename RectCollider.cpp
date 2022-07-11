#include "RectCollider.h"

template <class T>
bool RectCollider<T>::isCollide(std::shared_ptr<RectCollider> target) {
    if (target->top() >= bottom() && target->bottom() <= top() &&
        target->left() >= right() && target->right() <= left()) {
        return true;
    }
    return false;
}

template <class T>
bool RectCollider<T>::isCollide() {
    //・TODO：マップ地形との衝突判定（マップはどこから参照する？）
    if (false) {
        return true;
    }
    return false;
}

template <class T>
int RectCollider<T>::top() {
    return this->m_holderPtr->y() + this->m_dy;
}

template <class T>
int RectCollider<T>::bottom() {
    return top() + this->height;
}

template <class T>
int RectCollider<T>::left() {
    return this->m_holderPtr->x() + this->m_dx;
}

template <class T>
int RectCollider<T>::right() {
    return left() + this->width;
}