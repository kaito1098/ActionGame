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
    //・temp：計算用の一時変数、work：復元候補座標の保持用
    int x = m_holderPtr->getX(), temp_x = x;
    int y = m_holderPtr->getY(), temp_y = y;
    int distance = 0, temp_distance;
    //・上下左右の当たり判定を検証し、通行不可領域にめり込んでいる場合は最も近い通行可能領域へ復元する
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
    bool leftCheck = mapPtr->checkPassable(left(x), bottom(y) + 1);
    bool rightCheck = mapPtr->checkPassable(right(x), bottom(y) + 1);
    if (!(leftCheck && rightCheck)) {
        //・通行不可領域にめり込んだ場合、めり込まない位置まで上昇させる
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
    //・コライダー領域の 1 ピクセル右が通行可能か？を判定する
    bool topCheck = mapPtr->checkPassable(right(x) + 1, top(y));
    bool bottomCheck = mapPtr->checkPassable(right(x) + 1, bottom(y));
    if (!(topCheck && bottomCheck)) {
        //・通行不可領域にめり込んだ場合、めり込まない位置まで左に移動させる
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
    //・コライダー領域の 1 ピクセル上が通行可能か？を判定する
    bool leftCheck = mapPtr->checkPassable(left(x), top(y) - 1);
    bool rightCheck = mapPtr->checkPassable(right(x), top(y) - 1);
    if (!(leftCheck && rightCheck)) {
        //・通行不可領域にめり込んだ場合、めり込まない位置まで下降させる
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
    //・コライダー領域の 1 ピクセル右が通行可能か？を判定する
    bool topCheck = mapPtr->checkPassable(left(x) - 1, top(y));
    bool bottomCheck = mapPtr->checkPassable(left(x) - 1, bottom(y));
    if (!(topCheck && bottomCheck)) {
        //・通行不可領域にめり込んだ場合、めり込まない位置まで右に移動させる
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