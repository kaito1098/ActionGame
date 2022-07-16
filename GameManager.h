#pragma once
#include <memory>

class Map;
class Player;
class EnemyMushroom;

/** @brief ゲーム全体を管理するマネージャクラス */
class GameManager {
public:
	/**
	 * @brief ゲームのメイン処理
	 */
	void main();

	/**
	 * @brief 現在のマップを指すポインタを取得
	 * @return 現在のマップを指すポインタ
	 */
	std::shared_ptr<Map> getMapPtr();

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

	/** @brief 現在のマップを指すポインタ */
	std::shared_ptr<Map> mapPtr;

	/** @brief プレイヤーキャラクターを指すポインタ */
	std::unique_ptr<Player> playerPtr;

	//・TODO：EnemyはManager管理にする
	/** @brief 敵キャラクターを管理するマネージャを指すポインタ */
	std::unique_ptr<EnemyMushroom> mushroomPtr;
};

/** @brief ゲームマネージャ */
extern std::unique_ptr<GameManager> gameManagerPtr;