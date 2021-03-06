#pragma once
#include "IColliderHolder.h"
#include <vector>
#include <memory>

class IColliderHolder;
class AnimationManager;
class ICollider;

/** @brief アニメーションとコライダーを保持するキャラクターの基底クラス */
class IActor : public IColliderHolder {
public:
    /**
     * @brief コンストラクタ
     * @param _x：初期位置（x座標）
     * @param _y：初期位置（y座標）
     * @param _speed：移動速度
     * @param _xSize：画像の横幅
     * @param _ySize：画像の縦幅
     */
    IActor(int x, int y, int speed, int xSize, int ySize);

    /**
     * @brief 【仮想関数】デストラクタ
     */
    virtual ~IActor() = default;

    /**
     * @brief 位置情報、アニメーションなどの更新処理
     */
    void update();

    /**
     * @brief 現在の状態に基づいた描画処理
     * @param (screenX) スクリーン座標（x軸方向）
     * @param (screenY) スクリーン座標（y軸方向）
     */
    void draw(int screenX, int screenY);

    /**
     * @brief 描画座標（x軸）のゲッター
     * @return 描画座標（x軸）
     */
    int getX() override;

    /**
     * @brief 描画座標（y軸）のゲッター
     * @return 描画座標（y軸）
     */
    int getY() override;

protected:
    /** @brief 描画座標（x軸） */
    int m_x;

    /** @brief 描画座標（y軸） */
    int m_y;

    /** @brief 基準となる移動スピード */
    int m_baseSpeed;

    /** @brief １フレームあたりの移動距離（x軸） */
    int m_xSpeed;

    /** @brief １フレームあたりの移動距離（y軸） */
    int m_ySpeed;

    /** @brief 画像の横幅 */
    int m_xSize;

    /** @brief 画像の縦幅 */
    int m_ySize;

    /** @brief 左右反転描画フラグ（true：右向き、false：左向き） */
    bool m_turn;

    /** @brief 落下中フラグ（true：落下中である、false：落下中でない） */
    bool m_falling;

    /** @brief アニメーションマネージャへのポインタ */
    std::unique_ptr<AnimationManager> m_animationManagerPtr;

    /** @brief 当たり判定 */
    std::unique_ptr<ICollider> collider;

    /**
     * @brief アクターの描画位置を array 指定によりセットする
     * @param (pos) x座標、y座標を要素に持つ array
     */
    void setPositionByArray(std::array<int, 2> pos);

    /**
     * @brief 落下判定処理（setupから呼び出される想定）
     * @param (animId) 落下中のアニメーションID
     */
    void fall(int animId);

    /**
     * @brief 【仮想関数】update()が呼ばれる前のセットアップ（キー入力やAI操作による移動速度の決定など）
     */
    virtual void setup() = 0;
};