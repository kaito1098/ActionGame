#include "BaseActor.h"
#include "Common.h"

BaseActor::BaseActor(int _x, int _y, int _speed, int _xSize, int _ySize) :
	x(_x), y(_y), speed(_speed), xSize(_xSize), ySize(_ySize), xSpeed(0), ySpeed(0), turn(false) {
}

void BaseActor::update() {
	setup();
	x += xSpeed;
	y += ySpeed;
	animationManagerPtr->update();
}

void BaseActor::draw() {
	//�E�摜���オ���_�Ȃ̂ŁA�^���I�Ɍ��_�����[�����ƂȂ�悤�������Ă���
	animationManagerPtr->draw(x - xSize / 2, y - ySize, turn);
}

bool BaseActor::checkFalling() {
	//TODO�F���ۂɂ͂ǂ����肷�ׂ����H
	return y < (GROUND_HEIGHT);
}