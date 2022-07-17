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

bool RectCollider::isMapCollide() {
    std::shared_ptr<Map> mapPtr = gameManagerPtr->getMapPtr();
    bool collide = false;
    //・TODO：コライダー側からアクターの位置を書き換えるんでなくて、書き換えるべき位置を返すようにする
    //collide = isMapCollideCeiling(mapPtr) || collide;
    //collide = isMapCollideRight(mapPtr) || collide;
    //collide = isMapCollideLeft(mapPtr) || collide;
    collide = isMapCollideFloor(mapPtr) || collide;
    return collide;
}

bool RectCollider::isFalling() {
    std::shared_ptr<Map> mapPtr = gameManagerPtr->getMapPtr();
    //・コライダー領域の 1 ピクセル下が通行可能か？を判定する
    bool leftCheck = mapPtr->checkPassable(left(), bottom() + 1);
    bool rightCheck = mapPtr->checkPassable(right(), bottom() + 1);
    return leftCheck && rightCheck;
}

bool RectCollider::isMapCollideCeiling(std::shared_ptr<Map> mapPtr) {
    //・コライダー領域の 1 ピクセル上が通行可能か？を判定する
    bool leftCheck = mapPtr->checkPassable(left(), top() - 1);
    bool rightCheck = mapPtr->checkPassable(right(), top() - 1);
    if (leftCheck && rightCheck) {
        return true;
    } else {
        //・通行不可領域にめり込んだ場合、めり込まない位置まで下降させる
        int over = 0;
        while (!mapPtr->checkPassable(leftCheck ? right() : left(), top() + over) && top() + over < SCREEN_HEIGHT) {
            over++;
        }
        m_holderPtr->setY(m_holderPtr->getY() + over);
        return false;
    }
}

bool RectCollider::isMapCollideRight(std::shared_ptr<Map> mapPtr) {
    //・コライダー領域の 1 ピクセル右が通行可能か？を判定する
    bool topCheck = mapPtr->checkPassable(right() + 1, top());
    bool bottomCheck = mapPtr->checkPassable(right() + 1, bottom());
    if (topCheck && bottomCheck) {
        return true;
    } else {
        //・通行不可領域にめり込んだ場合、めり込まない位置まで左に移動させる
        int over = 0;
        while (!mapPtr->checkPassable(right() - over, topCheck ? bottom() : top()) && over < right()) {
            over++;
        }
        m_holderPtr->setX(m_holderPtr->getX() - over);
        return false;
    }
}

bool RectCollider::isMapCollideLeft(std::shared_ptr<Map> mapPtr) {
    //・コライダー領域の 1 ピクセル右が通行可能か？を判定する
    bool topCheck = mapPtr->checkPassable(left() - 1, top());
    bool bottomCheck = mapPtr->checkPassable(left() - 1, bottom());
    if (topCheck && bottomCheck) {
        return true;
    } else {
        //・通行不可領域にめり込んだ場合、めり込まない位置まで右に移動させる
        int over = 0;
        while (!mapPtr->checkPassable(left() + over, topCheck ? bottom() : top()) && left() + over < SCREEN_WIDTH) {
            over++;
        }
        m_holderPtr->setX(m_holderPtr->getX() + over);
        return false;
    }
}

bool RectCollider::isMapCollideFloor(std::shared_ptr<Map> mapPtr) {
    //・コライダー領域の 1 ピクセル下が通行可能か？を判定する
    bool leftCheck = mapPtr->checkPassable(left(), bottom() + 1);
    bool rightCheck = mapPtr->checkPassable(right(), bottom() + 1);
    if (leftCheck && rightCheck) {
        return true;
    } else {
        //・通行不可領域にめり込んだ場合、めり込まない位置まで上昇させる
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