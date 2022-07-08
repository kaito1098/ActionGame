#pragma once
#include <memory>
#include <vector>
#include <list>
#include "BaseCollider.h"

class BaseCollider;

class ColliderManager {
public:
    ColliderManager();
    int push(int nodeIdx, std::shared_ptr<BaseCollider> colliderPtr);
    void remove(int nodeIdx, int colliderIdx);
    void judgeCollide();
private:
    std::vector<std::list<std::shared_ptr<BaseCollider>>> collidersTree;   //・四分木によるコライダー管理
};