#include "GameManager.h"
#include "Common.h"
#include "DxLib.h"

//�E�w�i�摜�iTODO�F�e�X�g�p�Ȃ̂ł��Ƃŏ����j
int backGraph = 0;

void GameManager::main() {
	init();
	SetDrawScreen(DX_SCREEN_BACK);
	SetWindowSizeExtendRate(2.0);

	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen()) {
		update();
		draw();
	}
}

void GameManager::init() {
	//�E�w�i�摜�iTODO�F�e�X�g�p�Ȃ̂ł��Ƃŏ����j
	backGraph = LoadGraph("Data/Test/Forest.png");
	//�E���y��炷�iTODO�F���y�̓V�[���}�l�[�W���Ƃ��ŊǗ��H�j
	int sound = LoadSoundMem("Data/Test/Forest.wav");
	SetLoopSamplePosSoundMem(384000, sound);
	PlaySoundMem(sound, DX_PLAYTYPE_LOOP);
	playerPtr = std::make_unique<Player>(100, GROUND_HEIGHT);
	mushroomPtr = std::make_unique<EnemyMushroom>(500, GROUND_HEIGHT - 6);
}

void GameManager::update() {
	DrawGraph(0, 0, backGraph, FALSE);
	playerPtr->update();
	mushroomPtr->update();
}

void GameManager::draw() {
	playerPtr->draw();
	mushroomPtr->draw();
}