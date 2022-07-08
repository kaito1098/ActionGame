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
	//・画像左上が原点なので、疑似的に原点が下端中央となるよう調整している
	animationManagerPtr->draw(x - xSize / 2, y - ySize, turn);
}

bool BaseActor::checkFalling() {
	//TODO：実際にはどう判定すべきか？
	return y < (GROUND_HEIGHT);
}