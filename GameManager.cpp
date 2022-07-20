#include "Common.h"
#include "DxLib.h"

void GameManager::main() {
	init();
	SetDrawScreen(DX_SCREEN_BACK);

	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen()) {
		update();
		draw();
	}
}

std::shared_ptr<Map> GameManager::getMapPtr() {
	return mapPtr;
}

void GameManager::init() {
	//・オブジェクト生成
	mapPtr = std::make_shared<Map>("Data/Tileset/mapA.dat");
	playerPtr = std::make_unique<Player>(100, 200);
	mushroomPtr = std::make_unique<EnemyMushroom>(500, GROUND_HEIGHT);
	//・音楽を鳴らす（TODO：音楽はシーンマネージャとかで管理？）
	int sound = LoadSoundMem("Data/Test/Forest.wav");
	SetLoopSamplePosSoundMem(384000, sound);
	ChangeVolumeSoundMem(128, sound);
	PlaySoundMem(sound, DX_PLAYTYPE_LOOP);
}

void GameManager::update() {
	playerPtr->update();
	mushroomPtr->update();
}

void GameManager::draw() {
	//・TODO：プレイヤーの中心座標を取得するメソッドが欲しい
	//・スクリーン位置の設定（プレイヤーを中心に。ただしマップ領域外は映さない）
	std::array<int, 2> pos = playerPtr->getCenterPosition();
	screenX = min(mapPtr->getMapWidth() - SCREEN_WIDTH, max(0, pos[0] - SCREEN_WIDTH / 2));
	screenY = min(mapPtr->getMapHeight() - SCREEN_HEIGHT, max(0, pos[1] - SCREEN_HEIGHT / 2));
	//・TODO：各drawでオフセットの設定ができるように
	mapPtr->draw(screenX, screenY);
	playerPtr->draw(screenX, screenY);
	mushroomPtr->draw(screenX, screenY);
}

std::unique_ptr<GameManager> gameManagerPtr = std::make_unique<GameManager>();