#include "ColliderManager.h"

ColliderManager::ColliderManager() {
    //・四分木の初期化
    int nodeNum = 0;
    for (int i = 0; i < COLLIDERS_TREE_LEVEL; i++) {
        nodeNum += (int)pow(4, i);
    }
    collidersTree = std::vector<std::list<std::shared_ptr<BaseCollider>>>(nodeNum);
}

int ColliderManager::push(int nodeIdx, std::shared_ptr<BaseCollider> colliderPtr) {
    //・指定された空間ノードのidxにColliderを追加
    collidersTree[nodeIdx].emplace_back(colliderPtr);
    return collidersTree[nodeIdx].size() - 1;
}

void ColliderManager::remove(int nodeIdx, int colliderIdx) {
    //・指定された空間ノードのColliderを削除
    auto itr = collidersTree[nodeIdx].begin();
    for (int i = 0; i < colliderIdx; i++) {
        itr++;
        if (itr == collidersTree[nodeIdx].end()) return;
    }
    collidersTree[nodeIdx].erase(itr);
}

void ColliderManager::judgeCollide() {

}