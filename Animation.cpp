#include "Animation.h"
#include "DxLib.h"

Animation::Animation(const char* _filePath, int _allNum, int _xNum, int _yNum, int _xSize, int _ySize, int _animFrameCnt, bool _enabledLoop, int _busyLevel) :
	spritesIdx(0), frameCnt(0),
	filePath(_filePath), allNum(_allNum), xNum(_xNum), yNum(_yNum), xSize(_xSize), ySize(_ySize),
	animFrameCnt(_animFrameCnt), enabledLoop(_enabledLoop), busyLevel(_busyLevel) {
	sprites = std::vector<int>(allNum);
	LoadDivGraph(filePath, allNum, xNum, yNum, xSize, ySize, sprites.data());
}

bool Animation::update() {
	frameCnt++;
	if (frameCnt % animFrameCnt == 0) {
		spritesIdx++;
	}
	if (spritesIdx == allNum) {
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

int Animation::getBusyLevel() {
	return busyLevel;
}