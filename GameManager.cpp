#include "GameManager.h"
#include "Common.h"
#include "DxLib.h"

//�ETODO�F�e�X�g�p
#include "BaseMap.h"
std::unique_ptr<BaseMap> mapPtr;

//�E�w�i�摜�iTODO�F�e�X�g�p�Ȃ̂ł��Ƃŏ����j
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
	//�E���y��炷�iTODO�F���y�̓V�[���}�l�[�W���Ƃ��ŊǗ��H�j
	/*int sound = LoadSoundMem("Data/Test/Forest.wav");
	SetLoopSamplePosSoundMem(384000, sound);
	PlaySoundMem(sound, DX_PLAYTYPE_LOOP);*/
	//�ETODO�F�e�X�g�p
	mapPtr = std::make_unique<BaseMap>("Data/Tileset/mapA.dat");
}

void GameManager::update() {
	playerPtr->update();
	mushroomPtr->update();
}

void GameManager::draw() {
	//�ETODO�F�e�X�g�p
	mapPtr->draw();
	playerPtr->draw();
	mushroomPtr->draw();
}