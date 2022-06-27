#include "Player.h"

/**
 * @brief プレイヤーキャラクタークラスのコンストラクタ
 * @param _x：初期位置（x座標）
 * @param _y：初期位置（y座標）
 */
Player::Player(int _x, int _y) :
	x(_x), y(_y)
{
	//・使用するアニメーション一式の準備（一番目に指定したアニメーションがデフォルトアニメーションとなる）
	animationManagerPtr = std::make_shared<AnimationManager>();
	animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Hero/Idle.png", 11, 11, 1, 140, 140, 6, true));	//・０
}

void Player::update() {
	animationManagerPtr->update();
}

void Player::draw() {
	animationManagerPtr->draw(x - 70, y - 70);
}