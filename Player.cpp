#include "Player.h"
#include "Common.h"
#include "KeyInput.h"

/**
 * @brief プレイヤーキャラクタークラスのコンストラクタ
 * @param _x：初期位置（x座標）
 * @param _y：初期位置（y座標）
 */
Player::Player(int _x, int _y) :
	x(_x), y(_y), speed(2), xSpeed(0), ySpeed(0), turn(false) {
	//・使用するアニメーション一式の準備（一番目に指定したアニメーションがデフォルトアニメーションとなる）
	animationManagerPtr = std::make_shared<AnimationManager>();
	animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Hero/Idle.png", 11, 11, 1, 140, 140, 6, true));		//・０
	animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Hero/Run.png", 8, 8, 1, 140, 140, 4, true));			//・１
	animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Hero/Jump.png", 4, 4, 1, 140, 140, 8, false));			//・２
	animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Hero/Attack.png", 6, 6, 1, 140, 140, 6, false, true));	//・３
}

void Player::update() {
	if (!animationManagerPtr->isBusy()) {
		if (checkFalling()) {
			//・落下速度計算
			if (ySpeed < 10) ySpeed++;
		} else {
			//・落花中でなければキー操作による制御
			if (KeyInput::RIGHT.onPressed()) {
				turn = false;
				xSpeed = speed;
				animationManagerPtr->change(1);
			} else if (KeyInput::LEFT.onPressed()) {
				turn = true;
				xSpeed = -speed;
				animationManagerPtr->change(1);
			} else {
				xSpeed = 0;
				animationManagerPtr->change(0);
			}
			if (KeyInput::Z.onPressedOnce()) {
				ySpeed = -12;
				animationManagerPtr->change(2);
			} else if (KeyInput::X.onPressedOnce()) {
				xSpeed = 0;
				animationManagerPtr->change(3);
			}
		}
		x += xSpeed;
		y += ySpeed;
		//・着地
		if (!checkFalling()) {
			y = SCREEN_HEIGHT / 2;
			ySpeed = 0;
		}
	}
	animationManagerPtr->update();
}

void Player::draw() {
	animationManagerPtr->draw(x - 70, y - 70, turn);
}

bool Player::checkFalling() {
	//TODO：実際にはどう判定すべきか？
	return y < (SCREEN_HEIGHT / 2);
}