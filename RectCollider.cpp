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

std::array<int, 2> RectCollider::checkMapCollide() {
    std::shared_ptr<Map> mapPtr = gameManagerPtr->getMapPtr();
    int x = m_holderPtr->getX();
    int y = m_holderPtr->getY();
    //�ETODO�F�����^�C�~���O�őS���ʂ̓����蔻�������̂͌������H���̂Ƃ��� Floor ����΂��肪�����đ����@�\���ĂȂ��B�B
    //�E�㉺���E�̓����蔻������؂��A�ʍs�s�̈�ɂ߂荞�܂Ȃ����߂̕`����W���v�Z����
    if (checkMapCollideFloor(mapPtr, x, y)) return std::array<int, 2>{x, y};
    if (checkMapCollideRight(mapPtr, x, y)) return std::array<int, 2>{x, y};
    if (checkMapCollideCeiling(mapPtr, x, y)) return std::array<int, 2>{x, y};
    if (checkMapCollideLeft(mapPtr, x, y)) return std::array<int, 2>{x, y};
    return std::array<int, 2>{x, y};
}

//�ETODO�F�����Ԃ�������ɂ����肪�K�v�����i Actor ���ŏ�����̑��x�� 0 �ɂ��Ȃ��Ⴂ���Ȃ��j
bool RectCollider::isFalling() {
    std::shared_ptr<Map> mapPtr = gameManagerPtr->getMapPtr();
    //�E�R���C�_�[�̈�� 1 �s�N�Z�������ʍs�\���H�𔻒肷��
    bool leftCheck = mapPtr->checkPassable(left(), bottom() + 1);
    bool rightCheck = mapPtr->checkPassable(right(), bottom() + 1);
    return leftCheck && rightCheck;
}

bool RectCollider::checkMapCollideFloor(std::shared_ptr<Map> mapPtr, int& x, int& y) {
    //�E�R���C�_�[�̈�� 1 �s�N�Z�������ʍs�\���H�𔻒肷��
    bool leftCheck = mapPtr->checkPassable(left(), bottom() + 1);
    bool rightCheck = mapPtr->checkPassable(right(), bottom() + 1);
    if (!(leftCheck && rightCheck)) {
        //�E�ʍs�s�̈�ɂ߂荞�񂾏ꍇ�A�߂荞�܂Ȃ��ʒu�܂ŏ㏸������
        int over = 0;
        while (!mapPtr->checkPassable(leftCheck ? right() : left(), bottom() - over) && over < bottom()) {
            over++;
        }
        y = m_holderPtr->getY() - over;
        return true;
    }
    return false;
}

bool RectCollider::checkMapCollideRight(std::shared_ptr<Map> mapPtr, int& x, int& y) {
    //�E�R���C�_�[�̈�� 1 �s�N�Z���E���ʍs�\���H�𔻒肷��
    bool topCheck = mapPtr->checkPassable(right() + 1, top());
    bool bottomCheck = mapPtr->checkPassable(right() + 1, bottom());
    if (!(topCheck && bottomCheck)) {
        //�E�ʍs�s�̈�ɂ߂荞�񂾏ꍇ�A�߂荞�܂Ȃ��ʒu�܂ō��Ɉړ�������
        int over = 0;
        while (!mapPtr->checkPassable(right() - over, topCheck ? bottom() : top()) && over < right()) {
            over++;
        }
        x = m_holderPtr->getX() - over;
        return true;
    }
    return false;
}

bool RectCollider::checkMapCollideCeiling(std::shared_ptr<Map> mapPtr, int& x, int& y) {
    //�E�R���C�_�[�̈�� 1 �s�N�Z���オ�ʍs�\���H�𔻒肷��
    bool leftCheck = mapPtr->checkPassable(left(), top() - 1);
    bool rightCheck = mapPtr->checkPassable(right(), top() - 1);
    if (!(leftCheck && rightCheck)) {
        //�E�ʍs�s�̈�ɂ߂荞�񂾏ꍇ�A�߂荞�܂Ȃ��ʒu�܂ŉ��~������
        int over = 0;
        while (!mapPtr->checkPassable(leftCheck ? right() : left(), top() + over) && top() + over < SCREEN_HEIGHT) {
            over++;
        }
        y = m_holderPtr->getY() + over;
        return true;
    }
    return false;
}

bool RectCollider::checkMapCollideLeft(std::shared_ptr<Map> mapPtr, int& x, int& y) {
    //�E�R���C�_�[�̈�� 1 �s�N�Z���E���ʍs�\���H�𔻒肷��
    bool topCheck = mapPtr->checkPassable(left() - 1, top());
    bool bottomCheck = mapPtr->checkPassable(left() - 1, bottom());
    if (!(topCheck && bottomCheck)) {
        //�E�ʍs�s�̈�ɂ߂荞�񂾏ꍇ�A�߂荞�܂Ȃ��ʒu�܂ŉE�Ɉړ�������
        int over = 0;
        while (!mapPtr->checkPassable(left() + over, topCheck ? bottom() : top()) && left() + over < SCREEN_WIDTH) {
            over++;
        }
        x = m_holderPtr->getX() + over;
        return true;
    }
    return false;
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