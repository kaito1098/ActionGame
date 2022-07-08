#pragma once
#include "BaseActor.h"
#include "Common.h"
#include <memory>

class BaseCollider {
public:
    BaseCollider(std::shared_ptr<BaseActor> holderPtr);
    void hit(std::shared_ptr<BaseActor> object);
protected:
    std::shared_ptr<BaseActor> holderPtr;
    int colliderIdx;    //�E��ԓ���Collider���X�g�ɂ�����C���f�b�N�X�i�l���؊Ǘ��p�j
    virtual void pushCollidersTree() = 0;
    unsigned long getNodeIndexForRect(int left, int top, int right, int bottom);
    unsigned long getNodeIndexForPoint(int x, int y);
};