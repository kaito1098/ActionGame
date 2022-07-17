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

std::array<int, 2> RectCollider::checkMapCollide() {
    std::shared_ptr<Map> mapPtr = gameManagerPtr->getMapPtr();
    int x = m_holderPtr->getX();
    int y = m_holderPtr->getY();
    //・TODO：同じタイミングで全方位の当たり判定をするのは厳しい？今のところ Floor 判定ばかりが効いて他が機能してない。。
    //・上下左右の当たり判定を検証し、通行不可領域にめり込まないための描画座標を計算する
    if (checkMapCollideFloor(mapPtr, x, y)) return std::array<int, 2>{x, y};
    if (checkMapCollideRight(mapPtr, x, y)) return std::array<int, 2>{x, y};
    if (checkMapCollideCeiling(mapPtr, x, y)) return std::array<int, 2>{x, y};
    if (checkMapCollideLeft(mapPtr, x, y)) return std::array<int, 2>{x, y};
    return std::array<int, 2>{x, y};
}

//・TODO：頭をぶつける方向にも判定が必要かも（ Actor 側で上方向の速度を 0 にしなきゃいけない）
bool RectCollider::isFalling() {
    std::shared_ptr<Map> mapPtr = gameManagerPtr->getMapPtr();
    //・コライダー領域の 1 ピクセル下が通行可能か？を判定する
    bool leftCheck = mapPtr->checkPassable(left(), bottom() + 1);
    bool rightCheck = mapPtr->checkPassable(right(), bottom() + 1);
    return leftCheck && rightCheck;
}

bool RectCollider::checkMapCollideFloor(std::shared_ptr<Map> mapPtr, int& x, int& y) {
    //・コライダー領域の 1 ピクセル下が通行可能か？を判定する
    bool leftCheck = mapPtr->checkPassable(left(), bottom() + 1);
    bool rightCheck = mapPtr->checkPassable(right(), bottom() + 1);
    if (!(leftCheck && rightCheck)) {
        //・通行不可領域にめり込んだ場合、めり込まない位置まで上昇させる
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
    //・コライダー領域の 1 ピクセル右が通行可能か？を判定する
    bool topCheck = mapPtr->checkPassable(right() + 1, top());
    bool bottomCheck = mapPtr->checkPassable(right() + 1, bottom());
    if (!(topCheck && bottomCheck)) {
        //・通行不可領域にめり込んだ場合、めり込まない位置まで左に移動させる
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
    //・コライダー領域の 1 ピクセル上が通行可能か？を判定する
    bool leftCheck = mapPtr->checkPassable(left(), top() - 1);
    bool rightCheck = mapPtr->checkPassable(right(), top() - 1);
    if (!(leftCheck && rightCheck)) {
        //・通行不可領域にめり込んだ場合、めり込まない位置まで下降させる
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
    //・コライダー領域の 1 ピクセル右が通行可能か？を判定する
    bool topCheck = mapPtr->checkPassable(left() - 1, top());
    bool bottomCheck = mapPtr->checkPassable(left() - 1, bottom());
    if (!(topCheck && bottomCheck)) {
        //・通行不可領域にめり込んだ場合、めり込まない位置まで右に移動させる
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