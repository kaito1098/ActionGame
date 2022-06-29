#include "BaseActor.h"
#include "Common.h"

/**
 * @brief プレイヤーキャラクタークラスのコンストラクタ
 * @param _x：初期位置（x座標）
 * @param _y：初期位置（y座標）
 */
BaseActor::BaseActor(int _x, int _y, int _speed, int _xSize, int _ySize) :
	x(_x), y(_y), speed(_speed), xSize(_xSize), ySize(_ySize), xSpeed(0), ySpeed(0), turn(false) {
}

//・移動量の反映、アニメーションのアップデート
void BaseActor::update() {
	setup();
	x += xSpeed;
	y += ySpeed;
	animationManagerPtr->update();
}

//・描画
void BaseActor::draw() {
	animationManagerPtr->draw(x - xSize / 2, y - ySize, turn);
}

//・空中にいるかどうか？
bool BaseActor::checkFalling() {
	//TODO：実際にはどう判定すべきか？
	return y < (GROUND_HEIGHT);
}