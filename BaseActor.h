#pragma once
#include "IColliderHolder.h"
#include "AnimationManager.h"
#include <vector>
#include <memory>

/** @brief アニメーションとコリジョンを保持するキャラクターの基底クラス */
class BaseActor : public IColliderHolder {
public:
    /**
     * @brief コンストラクタ
     * @param _x：初期位置（x座標）
     * @param _y：初期位置（y座標）
     * @param _speed：移動速度
     * @param _xSize：画像の横幅
     * @param _ySize：画像の縦幅
     */
    BaseActor(int x, int y, int speed, int xSize, int ySize);

    /**
     * @brief 【仮想関数】デストラクタ
     */
    virtual ~BaseActor() = default;

    /**
     * @brief 位置情報、アニメーションなどの更新処理
     */
    void update();

    /**
     * @brief 現在の状態に基づいた描画処理
     */
    void draw();

    /**
     * @brief 【仮想関数】ColliderHolderID のゲッター
     * @return ColliderHolderID
     */
    virtual ColliderID getColliderHolderID() = 0;

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

    /** @brief アニメーションマネージャへのポインタ */
    std::unique_ptr<AnimationManager> m_animationManagerPtr;

    /**
     * @brief 落下しているかどうか（着地しているかどうか）
     * @return true：落下している、false：落下していない
     */
    bool checkFalling();

    /**
     * @brief 【仮想関数】update()が呼ばれる前のセットアップ（キー入力やAI操作による移動速度の決定など）
     */
    virtual void setup() = 0;
};