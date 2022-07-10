#include "GameManager.h"
#include "Common.h"
#include "DxLib.h"

//・TODO：テスト用
#include "BaseMap.h"
std::unique_ptr<BaseMap> mapPtr;

//・背景画像（TODO：テスト用なのであとで消す）
int backGraph = 0;

void GameManager::main() {
	init();
	SetDrawScreen(DX_SCREEN_BACK);

	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen()) {
		update();
		draw();
	}
}

void GameManager::init() {
	playerPtr = std::make_unique<Player>(100, GROUND_HEIGHT);
	mushroomPtr = std::make_unique<EnemyMushroom>(500, GROUND_HEIGHT);
	//・音楽を鳴らす（TODO：音楽はシーンマネージャとかで管理？）
	/*int sound = LoadSoundMem("Data/Test/Forest.wav");
	SetLoopSamplePosSoundMem(384000, sound);
	PlaySoundMem(sound, DX_PLAYTYPE_LOOP);*/
	//・TODO：テスト用
	mapPtr = std::make_unique<BaseMap>("Data/Tileset/mapA.dat");
}

void GameManager::update() {
	playerPtr->update();
	mushroomPtr->update();
}

void GameManager::draw() {
	//・TODO：テスト用
	mapPtr->draw();
	playerPtr->draw();
	mushroomPtr->draw();
}