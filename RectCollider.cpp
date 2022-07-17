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
    //�Etemp�F�v�Z�p�̈ꎞ�ϐ��Awork�F���������W�̕ێ��p
    int x = m_holderPtr->getX(), temp_x = x;
    int y = m_holderPtr->getY(), temp_y = y;
    int distance = 0, temp_distance;
    //�E�㉺���E�̓����蔻������؂��A�ʍs�s�̈�ɂ߂荞��ł���ꍇ�͍ł��߂��ʍs�\�̈�֕�������
    for (int i = 0; i < 4; i++) {
        switch (i) {
        case 0:
            checkMapCollideFloor(mapPtr, temp_x, temp_y);
            break;
        case 1:
            checkMapCollideRight(mapPtr, temp_x, temp_y);
            break;
        case 2:
            checkMapCollideCeiling(mapPtr, temp_x, temp_y);
            break;
        case 3:
            checkMapCollideLeft(mapPtr, temp_x, temp_y);
            break;
        }
        temp_distance = abs(m_holderPtr->getX() - temp_x) + abs(m_holderPtr->getY() - temp_y);
        if (distance < temp_distance) {
            x = temp_x;
            y = temp_y;
            distance = temp_distance;
        }
    }
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
    bool leftCheck = mapPtr->checkPassable(left(x), bottom(y) + 1);
    bool rightCheck = mapPtr->checkPassable(right(x), bottom(y) + 1);
    if (!(leftCheck && rightCheck)) {
        //�E�ʍs�s�̈�ɂ߂荞�񂾏ꍇ�A�߂荞�܂Ȃ��ʒu�܂ŏ㏸������
        int over = 0;
        while (!mapPtr->checkPassable(leftCheck ? right(x) : left(x), bottom(y) - over) && over < bottom(y)) {
            over++;
        }
        y = y - over;
        return true;
    }
    return false;
}

bool RectCollider::checkMapCollideRight(std::shared_ptr<Map> mapPtr, int& x, int& y) {
    //�E�R���C�_�[�̈�� 1 �s�N�Z���E���ʍs�\���H�𔻒肷��
    bool topCheck = mapPtr->checkPassable(right(x) + 1, top(y));
    bool bottomCheck = mapPtr->checkPassable(right(x) + 1, bottom(y));
    if (!(topCheck && bottomCheck)) {
        //�E�ʍs�s�̈�ɂ߂荞�񂾏ꍇ�A�߂荞�܂Ȃ��ʒu�܂ō��Ɉړ�������
        int over = 0;
        while (!mapPtr->checkPassable(right(x) - over, topCheck ? bottom(y) : top(y)) && over < right(x)) {
            over++;
        }
        x = x - over;
        return true;
    }
    return false;
}

bool RectCollider::checkMapCollideCeiling(std::shared_ptr<Map> mapPtr, int& x, int& y) {
    //�E�R���C�_�[�̈�� 1 �s�N�Z���オ�ʍs�\���H�𔻒肷��
    bool leftCheck = mapPtr->checkPassable(left(x), top(y) - 1);
    bool rightCheck = mapPtr->checkPassable(right(x), top(y) - 1);
    if (!(leftCheck && rightCheck)) {
        //�E�ʍs�s�̈�ɂ߂荞�񂾏ꍇ�A�߂荞�܂Ȃ��ʒu�܂ŉ��~������
        int over = 0;
        while (!mapPtr->checkPassable(leftCheck ? right(x) : left(x), top(y) + over) && top(y) + over < SCREEN_HEIGHT) {
            over++;
        }
        y = y + over;
        return true;
    }
    return false;
}

bool RectCollider::checkMapCollideLeft(std::shared_ptr<Map> mapPtr, int& x, int& y) {
    //�E�R���C�_�[�̈�� 1 �s�N�Z���E���ʍs�\���H�𔻒肷��
    bool topCheck = mapPtr->checkPassable(left(x) - 1, top(y));
    bool bottomCheck = mapPtr->checkPassable(left(x) - 1, bottom(y));
    if (!(topCheck && bottomCheck)) {
        //�E�ʍs�s�̈�ɂ߂荞�񂾏ꍇ�A�߂荞�܂Ȃ��ʒu�܂ŉE�Ɉړ�������
        int over = 0;
        while (!mapPtr->checkPassable(left(x) + over, topCheck ? bottom(y) : top(y)) && left(x) + over < SCREEN_WIDTH) {
            over++;
        }
        x = x + over;
        return true;
    }
    return false;
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

int RectCollider::top(int y) {
    return y + m_dy;
}

int RectCollider::bottom(int y) {
    return top(y) + m_height;
}

int RectCollider::left(int x) {
    return x + m_dx;
}

int RectCollider::right(int x) {
    return left(x) + m_width;
}