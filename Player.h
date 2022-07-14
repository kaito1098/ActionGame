#pragma once
#include "BaseActor.h"
#include "RectCollider.h"

/** @brief プレイヤーキャラクター */
class Player : public BaseActor {
public:
	/**
	 * @brief コンストラクタ
	 * @param _x：初期位置（x座標）
	 * @param _y：初期位置（y座標）
	 * @remark アニメーションの登録はここで行っている。
	 */
	Player(int x, int y);

	/**
	 * @brief ColliderHolderID のゲッター
	 * @return ColliderHolderID
	 */
	ColliderID getColliderHolderID();

protected:
	/** @brief 当たり判定 */
	std::unique_ptr<RectCollider> collider;

	/**
	 * @brief キー入力による操作の実装
	 * @remark 十字キーで移動 TODO：2回押すとローリング
	 * @remark Zキーでジャンプ
	 * @remark Xキーで攻撃
	 * @remark LShiftキーでバックステップ
	 */
	void setup() override;
};