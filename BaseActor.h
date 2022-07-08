#pragma once
#include "AnimationManager.h"
#include <vector>
#include <memory>

/** @brief アニメーションとコリジョンを保持するキャラクターの基底クラス */
class BaseActor {
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
     * @brief 位置情報、アニメーションなどの更新処理
     */
    void update();

    /**
     * @brief 現在の状態に基づいた描画処理
     */
    void draw();

protected:
    /** @brief 描画座標（x軸） */
    int x;

    /** @brief 描画座標（y軸） */
    int y;

    /** @brief 基準となる移動スピード */
    int speed;

    /** @brief １フレームあたりの移動距離（x軸） */
    int xSpeed;

    /** @brief １フレームあたりの移動距離（y軸） */
    int ySpeed;

    /** @brief 画像の横幅（ピクセル） */
    int xSize;

    /** @brief 画像の縦幅（ピクセル） */
    int ySize;

    /** @brief 左右反転描画フラグ（true：右向き、false：左向き） */
    bool turn;

    /** @brief アニメーションマネージャへのポインタ */
    std::unique_ptr<AnimationManager> animationManagerPtr;

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