#include "Animation.h"
#include "DxLib.h"

Animation::Animation(const char* _filePath, int _allNum, int _xNum, int _yNum, int _xSize, int _ySize, int _animFrameCnt, bool _enabledLoop) :
	spritesIdx(0), frameCnt(0),
	filePath(_filePath), allNum(_allNum), xNum(_xNum), yNum(_yNum), xSize(_xSize), ySize(_ySize),
	animFrameCnt(_animFrameCnt), enabledLoop(_enabledLoop) {
	sprites = new int[allNum];
	LoadDivGraph(filePath, allNum, xNum, yNum, xSize, ySize, sprites);
}

Animation::~Animation() {
	delete[] sprites;
}

bool Animation::update() {
	frameCnt++;
	if (frameCnt % animFrameCnt == 0) {
		spritesIdx++;
	}
	if (spritesIdx == allNum) {
		//・アニメーション完了時、trueを返す（ループ有効時は常にfalse）
		spritesIdx = 0;
		return !enabledLoop;
	}
	return false;
}

void Animation::reset() {
	spritesIdx = 0;
	frameCnt = 0;
}

int Animation::getGraphHandle() {
	if (spritesIdx < allNum) {
		return sprites[spritesIdx];
	}
	return -1;
}