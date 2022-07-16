#pragma once
#include "IActor.h"

class IActor;

/** @brief マッシュルームモンスター */
class EnemyMushroom : public IActor {
public:
	/**
	 * @brief コンストラクタ
     * @param _x：初期位置（x座標）
     * @param _y：初期位置（y座標）
	 * @remark アニメーションの登録はここで行っている。
	 */
	EnemyMushroom(int x, int y);

	/**
	 * @brief ColliderHolderID のゲッター
	 * @return ColliderHolderID
	 */
	ColliderID getColliderHolderID();

protected:
	/**
	 * @brief AIによる挙動の実装
	 * @remark 平常時は一定間隔で左右に徘徊するのみ。
	 * @remark プレイヤーが一定範囲に近づくと、プレイヤーに近づいていく。
	 * @remark 攻撃可能範囲になったら攻撃モーションに入る。
	 */
	void setup() override;
};