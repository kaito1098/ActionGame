#pragma once
#include "Player.h"
#include "EnemyMushroom.h"
#include <memory>

/** @brief ゲーム全体を管理するマネージャクラス */
class GameManager {
public:
	/**
	 * @brief ゲームのメイン処理
	 */
	void main();

private:
	/**
	 * @brief 初期化処理
	 */
	void init();

	/**
	 * @brief 描画前の更新処理
	 */
	void update();

	/**
	 * @brief 描画処理
	 */
	void draw();

	/** @brief プレイヤーキャラクターを指すポインタ */
	std::unique_ptr<Player> playerPtr;

	//・TODO：EnemyはManager管理にする
	/** @brief 敵キャラクターを管理するマネージャを指すポインタ */
	std::unique_ptr<EnemyMushroom> mushroomPtr;
};