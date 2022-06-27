#include "Player.h"
#include "KeyInput.h"

/**
 * @brief プレイヤーキャラクタークラスのコンストラクタ
 * @param _x：初期位置（x座標）
 * @param _y：初期位置（y座標）
 */
Player::Player(int _x, int _y) :
	x(_x), y(_y), turn(false)
{
	//・使用するアニメーション一式の準備（一番目に指定したアニメーションがデフォルトアニメーションとなる）
	animationManagerPtr = std::make_shared<AnimationManager>();
	animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Hero/Idle.png", 11, 11, 1, 140, 140, 6, true));	//・０
	animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Hero/Run.png", 8, 8, 1, 140, 140, 4, true));		//・１
}

void Player::update() {
	if (KeyInput::RIGHT.onPressed()) {
		turn = false;
		x += 2;
		animationManagerPtr->change(1);
	} else if (KeyInput::LEFT.onPressed()) {
		turn = true;
		x -= 2;
		animationManagerPtr->change(1);
	} else {
		animationManagerPtr->change(0);
	}
	animationManagerPtr->update();
}

void Player::draw() {
	animationManagerPtr->draw(x - 70, y - 70, turn);
}