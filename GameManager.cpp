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
	playerPtr = std::make_unique<Player>(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
}

void GameManager::update() {
	playerPtr->update();
}

void GameManager::draw() {
	playerPtr->draw();
}