#include "Common.h"
#include "DxLib.h"

RectCollider::RectCollider(IColliderHolder* holderPtr, ColliderID id, int dx, int dy, int width, int height) :
    ICollider(holderPtr, id, dx, dy),
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

bool RectCollider::checkPassableOver(int x, int y) {
    std::shared_ptr<Map> mapPtr = gameManagerPtr->getMapPtr();
    //�E�R���C�_�[�̈�� 1 �s�N�Z���オ�ʍs�\���H�𔻒肷��
    bool leftCheck = mapPtr->checkPassable(left(x), top(y) - 1);
    bool rightCheck = mapPtr->checkPassable(right(x), top(y) - 1);
    return leftCheck && rightCheck;
}

bool RectCollider::checkPassableUnder(int x, int y) {
    std::shared_ptr<Map> mapPtr = gameManagerPtr->getMapPtr();
    //�E�R���C�_�[�̈�� 1 �s�N�Z�������ʍs�\���H�𔻒肷��
    bool leftCheck = mapPtr->checkPassable(left(x), bottom(y) + 1);
    bool rightCheck = mapPtr->checkPassable(right(x), bottom(y) + 1);
    return leftCheck && rightCheck;
}

bool RectCollider::checkPassableLeft(int x, int y) {
    std::shared_ptr<Map> mapPtr = gameManagerPtr->getMapPtr();
    //�E�R���C�_�[�̈�� 1 �s�N�Z���E���ʍs�\���H�𔻒肷��
    bool topCheck = mapPtr->checkPassable(left(x) - 1, top(y));
    bool bottomCheck = mapPtr->checkPassable(left(x) - 1, bottom(y));
    return topCheck && bottomCheck;
}

bool RectCollider::checkPassableRight(int x, int y) {
    std::shared_ptr<Map> mapPtr = gameManagerPtr->getMapPtr();
    //�E�R���C�_�[�̈�� 1 �s�N�Z���E���ʍs�\���H�𔻒肷��
    bool topCheck = mapPtr->checkPassable(right(x) + 1, top(y));
    bool bottomCheck = mapPtr->checkPassable(right(x) + 1, bottom(y));
    return topCheck && bottomCheck;
}

int RectCollider::getFloorY(int x, int y) {
    std::shared_ptr<Map> mapPtr = gameManagerPtr->getMapPtr();
    //�E�R���C�_�[�̉��[���ʍs�\�̈�ƂȂ�܂ŏ㏸������
    int amount = 0;
    while (amount < bottom(y)) {
        bool leftCheck = mapPtr->checkPassable(left(x), bottom(y) - amount);
        bool rightCheck = mapPtr->checkPassable(right(x), bottom(y) - amount);
        if (leftCheck && rightCheck) {
            return y - amount;
        } else {
            amount++;
        }
    }
    return 0;   //�E�ʍs�\�̈悪������Ȃ�
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