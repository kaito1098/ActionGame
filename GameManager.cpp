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
	mapPtr = std::make_shared<Map>("Data/Tileset/mapA.dat");
	playerPtr = std::make_unique<Player>(100, 200);
	mushroomPtr = std::make_unique<EnemyMushroom>(500, GROUND_HEIGHT);
	//�E���y��炷�iTODO�F���y�̓V�[���}�l�[�W���Ƃ��ŊǗ��H�j
	int sound = LoadSoundMem("Data/Test/Forest.wav");
	SetLoopSamplePosSoundMem(384000, sound);
	PlaySoundMem(sound, DX_PLAYTYPE_LOOP);
}

void GameManager::update() {
	playerPtr->update();
	mushroomPtr->update();
}

void GameManager::draw() {
	mapPtr->draw();
	playerPtr->draw();
	mushroomPtr->draw();
}

std::unique_ptr<GameManager> gameManagerPtr = std::make_unique<GameManager>();