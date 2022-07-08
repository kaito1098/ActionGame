#pragma once
#include "BaseCollider.h"

class RectCollider : public BaseCollider {
public:
    int top, bottom, left, right;   //・上下のy座標と左右のx座標
    bool isCollide(std::shared_ptr<RectCollider> target);
private:
    void pushCollidersTree() override;
};