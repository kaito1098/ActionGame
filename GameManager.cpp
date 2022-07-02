#include "GameManager.h"
#include "Common.h"
#include "DxLib.h"

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
	//・背景画像（TODO：テスト用なのであとで消す）
	backGraph = LoadGraph("Data/Test/Forest.png");
	//・音楽を鳴らす（TODO：音楽はシーンマネージャとかで管理？）
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