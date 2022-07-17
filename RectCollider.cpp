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

bool RectCollider::isMapCollide() {
    std::shared_ptr<Map> mapPtr = gameManagerPtr->getMapPtr();
    bool collide = false;
    //�ETODO�F�R���C�_�[������A�N�^�[�̈ʒu�������������łȂ��āA����������ׂ��ʒu��Ԃ��悤�ɂ���
    //collide = isMapCollideCeiling(mapPtr) || collide;
    //collide = isMapCollideRight(mapPtr) || collide;
    //collide = isMapCollideLeft(mapPtr) || collide;
    collide = isMapCollideFloor(mapPtr) || collide;
    return collide;
}

bool RectCollider::isFalling() {
    std::shared_ptr<Map> mapPtr = gameManagerPtr->getMapPtr();
    //�E�R���C�_�[�̈�� 1 �s�N�Z�������ʍs�\���H�𔻒肷��
    bool leftCheck = mapPtr->checkPassable(left(), bottom() + 1);
    bool rightCheck = mapPtr->checkPassable(right(), bottom() + 1);
    return leftCheck && rightCheck;
}

bool RectCollider::isMapCollideCeiling(std::shared_ptr<Map> mapPtr) {
    //�E�R���C�_�[�̈�� 1 �s�N�Z���オ�ʍs�\���H�𔻒肷��
    bool leftCheck = mapPtr->checkPassable(left(), top() - 1);
    bool rightCheck = mapPtr->checkPassable(right(), top() - 1);
    if (leftCheck && rightCheck) {
        return true;
    } else {
        //�E�ʍs�s�̈�ɂ߂荞�񂾏ꍇ�A�߂荞�܂Ȃ��ʒu�܂ŉ��~������
        int over = 0;
        while (!mapPtr->checkPassable(leftCheck ? right() : left(), top() + over) && top() + over < SCREEN_HEIGHT) {
            over++;
        }
        m_holderPtr->setY(m_holderPtr->getY() + over);
        return false;
    }
}

bool RectCollider::isMapCollideRight(std::shared_ptr<Map> mapPtr) {
    //�E�R���C�_�[�̈�� 1 �s�N�Z���E���ʍs�\���H�𔻒肷��
    bool topCheck = mapPtr->checkPassable(right() + 1, top());
    bool bottomCheck = mapPtr->checkPassable(right() + 1, bottom());
    if (topCheck && bottomCheck) {
        return true;
    } else {
        //�E�ʍs�s�̈�ɂ߂荞�񂾏ꍇ�A�߂荞�܂Ȃ��ʒu�܂ō��Ɉړ�������
        int over = 0;
        while (!mapPtr->checkPassable(right() - over, topCheck ? bottom() : top()) && over < right()) {
            over++;
        }
        m_holderPtr->setX(m_holderPtr->getX() - over);
        return false;
    }
}

bool RectCollider::isMapCollideLeft(std::shared_ptr<Map> mapPtr) {
    //�E�R���C�_�[�̈�� 1 �s�N�Z���E���ʍs�\���H�𔻒肷��
    bool topCheck = mapPtr->checkPassable(left() - 1, top());
    bool bottomCheck = mapPtr->checkPassable(left() - 1, bottom());
    if (topCheck && bottomCheck) {
        return true;
    } else {
        //�E�ʍs�s�̈�ɂ߂荞�񂾏ꍇ�A�߂荞�܂Ȃ��ʒu�܂ŉE�Ɉړ�������
        int over = 0;
        while (!mapPtr->checkPassable(left() + over, topCheck ? bottom() : top()) && left() + over < SCREEN_WIDTH) {
            over++;
        }
        m_holderPtr->setX(m_holderPtr->getX() + over);
        return false;
    }
}

bool RectCollider::isMapCollideFloor(std::shared_ptr<Map> mapPtr) {
    //�E�R���C�_�[�̈�� 1 �s�N�Z�������ʍs�\���H�𔻒肷��
    bool leftCheck = mapPtr->checkPassable(left(), bottom() + 1);
    bool rightCheck = mapPtr->checkPassable(right(), bottom() + 1);
    if (leftCheck && rightCheck) {
        return true;
    } else {
        //�E�ʍs�s�̈�ɂ߂荞�񂾏ꍇ�A�߂荞�܂Ȃ��ʒu�܂ŏ㏸������
        int over = 0;
        while (!mapPtr->checkPassable(leftCheck ? right() : left(), bottom() - over) && over < bottom()) {
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