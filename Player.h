#pragma once
#include "IActor.h"
#include <array>

/** @brief プレイヤーキャラクター */
class Player : public IActor {
public:
	/**
	 * @brief コンストラクタ
	 * @param _x：初期位置（x座標）
	 * @param _y：初期位置（y座標）
	 * @remark アニメーションの登録はここで行っている。
	 */
	Player(int x, int y);

	/**
	 * @brief プレイヤーの中心座標を取得する
	 * @return プレイヤーの中心座標（x, y）
	 */
	std::array<int, 2> getCenterPosition();

protected:
	/**
	 * @brief キー入力による操作の実装
	 * @remark 十字キーで移動 TODO：2回押すとローリング
	 * @remark Zキーでジャンプ
	 * @remark Xキーで攻撃
	 * @remark LShiftキーでバックステップ
	 */
	void setup() override;
};