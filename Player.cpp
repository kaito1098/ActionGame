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
	animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Hero/Attack.png", 6, 6, 1, 140, 140, 6, false, 1));	//・３
	animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Hero/Dash.png", 4, 4, 1, 140, 140, 4, false, 2));		//・４
}

void Player::update() {
	if (checkFalling()) {
		//・落下速度計算
		if (ySpeed < 10) ySpeed++;
		//・着地
		if (y + ySpeed >= SCREEN_HEIGHT / 2) {
			y = SCREEN_HEIGHT / 2;
			ySpeed = 0;
			xSpeed = 0;
		}
	} else {
		//・落下中でない場合、ビジーレベル０の各操作
		if (animationManagerPtr->getBusyLevel() <= 0) {
			//・左右移動
			if (KeyInput::RIGHT.onPressed()) {
				turn = false;
				xSpeed = speed;
				animationManagerPtr->change(1);
			}
			if (KeyInput::LEFT.onPressed()) {
				turn = true;
				xSpeed = -speed;
				animationManagerPtr->change(1);
			}
			//・ジャンプ
			if (KeyInput::Z.onPressedOnce()) {
				ySpeed = -12;
				animationManagerPtr->change(2);
			}
			//・アイドル状態
			if (!KeyInput::RIGHT.onPressed() && !KeyInput::LEFT.onPressed()) {
				xSpeed = 0;
				animationManagerPtr->change(0);
			}
		}
		//・バックステップ（ビジーレベル２）
		if (animationManagerPtr->getBusyLevel() <= 2) {
			if (KeyInput::LSHIFT.onPressedOnce()) {
				xSpeed = (turn ? speed : -speed) * 5;
				ySpeed = -5;
				animationManagerPtr->change(4);
			}
		}
	}
	//・攻撃（ビジーレベル１）
	if (animationManagerPtr->getBusyLevel() <= 1) {
		if (KeyInput::X.onPressedOnce()) {
			if (!checkFalling()) {
				//・地上で攻撃した場合は即座に移動停止
				xSpeed = 0;
			}
			animationManagerPtr->change(3);
		}
	}
	x += xSpeed;
	y += ySpeed;
	char buff[256];
	sprintf_s(buff, "%d\n", animationManagerPtr->getBusyLevel());
	OutputDebugString(buff);
	animationManagerPtr->update();
}

void Player::draw() {
	animationManagerPtr->draw(x - 70, y - 70, turn);
}

bool Player::checkFalling() {
	//TODO：実際にはどう判定すべきか？
	return y < (SCREEN_HEIGHT / 2);
}