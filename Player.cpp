#include "Common.h"

//・スプライト画像 1 コマ毎の画像サイズ
const int SPRITES_X_SIZE = 420;
const int SPRITES_Y_SIZE = 200;
//・各パラメータ
const int JUMP_FORCE = 28;	//・ジャンプ力

Player::Player(int _x, int _y) :
	IActor(_x, _y, 4, SPRITES_X_SIZE, SPRITES_Y_SIZE) {
	//・当たり判定
	collider = std::make_unique<RectCollider>(this, 160, 60, 100, 140);
	//・使用するアニメーション一式の準備（一番目に指定したアニメーションが待機アニメーションとなる）
	m_animationManagerPtr = std::make_unique<AnimationManager>();
	m_animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Hero/Idle.png", 11, 11, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE, 6, true));		//・０
	m_animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Hero/Run.png", 8, 8, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE, 4, true));			//・１
	m_animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Hero/Jump.png", 4, 4, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE, 8, false));			//・２
	m_animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Hero/Attack.png", 6, 6, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE, 6, false, 1));	//・３
	m_animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Hero/Dash.png", 4, 4, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE, 4, false, 2));		//・４
}

ColliderID Player::getColliderHolderID() {
	return ColliderID::Player;
}

void Player::setup() {
	if (collider->isFalling()) {
		//・落下
		m_animationManagerPtr->change(2);
		if (m_ySpeed < MAX_FALL_SPEED) m_ySpeed += GRAVITY;
	} else {
		//・着地
		//m_y = GROUND_HEIGHT;
		m_ySpeed = 0;
		m_xSpeed = 0;
		//・アイドル状態
		if (!KeyInput::RIGHT->onPressed() && !KeyInput::LEFT->onPressed()) {
			if (m_animationManagerPtr->change(0)) {
				m_xSpeed = 0;
			}
		}
		//・左右移動
		if (KeyInput::RIGHT->onPressed()) {
			if (m_animationManagerPtr->change(1)) {
				m_turn = false;
				m_xSpeed = m_baseSpeed;
			}
		}
		if (KeyInput::LEFT->onPressed()) {
			if (m_animationManagerPtr->change(1)) {
				m_turn = true;
				m_xSpeed = -m_baseSpeed;
			}
		}
		//・ジャンプ
		if (KeyInput::Z->onPressedOnce()) {
			if (m_animationManagerPtr->change(2)) {
				m_ySpeed = -JUMP_FORCE;
			}
		}
		//・バックステップ
		if (KeyInput::LSHIFT->onPressedOnce()) {
			if (m_animationManagerPtr->change(4)) {
				m_xSpeed = (m_turn ? m_baseSpeed : -m_baseSpeed) * 5;
				m_ySpeed = -5;
			}
		}
	}
	//・攻撃
	if (KeyInput::X->onPressedOnce()) {
		if (m_animationManagerPtr->change(3)) {
			if (!collider->isFalling()) {
				//・地上で攻撃した場合は即座に移動停止
				m_xSpeed = 0;
			}
		}

	}
}