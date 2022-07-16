#include "Common.h"
#include "DxLib.h"

RectCollider::RectCollider(IColliderHolder* holderPtr, int dx, int dy, int width, int height) :
    ICollider(holderPtr, dx, dy),
    m_width(width), m_height(height) {
}

void RectCollider::draw() {
    if (!DEBUG_FLAG) return;
    const int color = GetColor(255, 0, 0);
    DrawLine(left(), top(), right(), top(), color);         //�E���
    DrawLine(right(), top(), right(), bottom(), color);     //�E�E��
    DrawLine(left(), bottom(), right(), bottom(), color);   //�E����
    DrawLine(left(), top(), left(), bottom(), color);       //�E����
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
    //�E�R���C�_�[�̈�� 1 �s�N�Z�������ʍs�\���H�𔻒肷��
    bool leftCheck = mapPtr->getMapCollideID(left(), bottom() + 1) == MapCollideID::passable;
    bool rightCheck = mapPtr->getMapCollideID(right(), bottom() + 1) == MapCollideID::passable;
    if (leftCheck && rightCheck) {
        return true;
    } else {
        int over = 0;   //�E�߂荞�񂾃s�N�Z����
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