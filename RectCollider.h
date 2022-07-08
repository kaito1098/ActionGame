#pragma once
#include "BaseCollider.h"

class RectCollider : public BaseCollider {
public:
    int top, bottom, left, right;   //�E�㉺��y���W�ƍ��E��x���W
    bool isCollide(std::shared_ptr<RectCollider> target);
private:
    void pushCollidersTree() override;
};