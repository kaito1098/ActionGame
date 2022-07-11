#pragma once
#include <memory>
#include "BaseActor.h"

/** @brief 当たり判定の基底クラス */
template <class T>
class BaseCollider {
protected:
    /** @brief コンストラクタ */
    BaseCollider(std::shared_ptr<T> holder, int dx, int dy);

    /** @brief Collider を保持する Actor クラスを指すポインタ */
    std::shared_ptr<T> m_holderPtr;

    /** @brief 当たり判定を保持するオブジェクトからの相対座標（x軸方向） */
    int m_dx;

    /** @brief 当たり判定を保持するオブジェクトからの相対座標（y軸方向） */
    int m_dy;

    /**
     * @brief 【仮想関数】マップ地形との当たり判定
     * @param (arg) 
     * @return 戻り値の説明
     */
    virtual bool isCollide() = 0;
};