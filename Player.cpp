#include "Player.h"
#include "Common.h"
#include "KeyInput.h"

const int SPRITES_X_SIZE = 140;
const int SPRITES_Y_SIZE = 140;

/**
 * @brief プレイヤーキャラクタークラスのコンストラクタ
 * @param _x：初期位置（x座標）
 * @param _y：初期位置（y座標）
 */
Player::Player(int _x, int _y) :
	BaseActor(_x, _y, 2, SPRITES_X_SIZE, SPRITES_Y_SIZE) {
	//・使用するアニメーション一式の準備（一番目に指定したアニメーションが待機アニメーションとなる）
	animationManagerPtr = std::make_shared<AnimationManager>();
	animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Hero/Idle.png", 11, 11, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE, 6, true));		//・０
	animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Hero/Run.png", 8, 8, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE, 4, true));			//・１
	animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Hero/Jump.png", 4, 4, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE, 8, false));		//・２
	animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Hero/Attack.png", 6, 6, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE, 6, false, 1));	//・３
	animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Hero/Dash.png", 4, 4, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE, 4, false, 2));	//・４
}

//・キー入力による操作、アニメーション遷移と移動量のセットなど
void Player::setup() {
	if (checkFalling()) {
		//・落下速度計算
		if (ySpeed < MAX_FALL_SPEED) ySpeed++;
		//・着地
		if (y + ySpeed >= GROUND_HEIGHT) {
			y = GROUND_HEIGHT;
			ySpeed = 0;
			xSpeed = 0;
		}
	} else {
		//・落下中でない場合、ビジーレベル０の各操作
			//・左右移動
		if (KeyInput::RIGHT.onPressed()) {
			if (animationManagerPtr->change(1)) {
				turn = false;
				xSpeed = speed;
			}
		}
		if (KeyInput::LEFT.onPressed()) {
			if (animationManagerPtr->change(1)) {
				turn = true;
				xSpeed = -speed;
			}
		}
		//・ジャンプ
		if (KeyInput::Z.onPressedOnce()) {
			if (animationManagerPtr->change(2)) {
				ySpeed = -12;
			}
		}
		//・アイドル状態
		if (!KeyInput::RIGHT.onPressed() && !KeyInput::LEFT.onPressed()) {
			if (animationManagerPtr->change(0)) {
				xSpeed = 0;
			}
		}
		//・バックステップ
		if (KeyInput::LSHIFT.onPressedOnce()) {
			if (animationManagerPtr->change(4)) {
				xSpeed = (turn ? speed : -speed) * 5;
				ySpeed = -5;
			}
		}
	}
	//・攻撃
	if (KeyInput::X.onPressedOnce()) {
		if (animationManagerPtr->change(3)) {
			if (!checkFalling()) {
				//・地上で攻撃した場合は即座に移動停止
				xSpeed = 0;
			}
		}

	}
}