#include "Animation.h"
#include "DxLib.h"

Animation::Animation(const char* _filePath, int _allNum, int _xNum, int _yNum, int _xSize, int _ySize, int _animFrameCnt, bool _enabledLoop, bool _enabledBusy) :
	spritesIdx(0), frameCnt(0),
	filePath(_filePath), allNum(_allNum), xNum(_xNum), yNum(_yNum), xSize(_xSize), ySize(_ySize),
	animFrameCnt(_animFrameCnt), enabledLoop(_enabledLoop), enabledBusy(_enabledBusy), busy(_enabledBusy) {
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
		//�E�A�j���[�V�����������Atrue��Ԃ��i���[�v�L�����͏��false�j
		spritesIdx = 0;
		busy = false;
		return !enabledLoop;
	}
	return false;
}

void Animation::reset() {
	spritesIdx = 0;
	frameCnt = 0;
	busy = enabledBusy;
}

int Animation::getGraphHandle() {
	if (spritesIdx < allNum) {
		return sprites[spritesIdx];
	}
	return -1;
}

bool Animation::isBusy() {
	return busy;
}