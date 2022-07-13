#include "GameManager.h"
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

void GameManager::init() {
	mapPtr = std::make_unique<Map>("Data/Tileset/mapA.dat");
	playerPtr = std::make_unique<Player>(100, GROUND_HEIGHT);
	mushroomPtr = std::make_unique<EnemyMushroom>(500, GROUND_HEIGHT);
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