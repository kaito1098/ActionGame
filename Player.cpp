#include "Player.h"
#include "Common.h"
#include "KeyInput.h"

const int SPRITES_X_SIZE = 420;
const int SPRITES_Y_SIZE = 420;

Player::Player(int _x, int _y) :
	BaseActor(_x, _y, 2, SPRITES_X_SIZE, SPRITES_Y_SIZE) {
	//�E�����蔻��
	collider = std::make_unique<RectCollider>(this, 20, 40, 100, 200);
	//�E�g�p����A�j���[�V�����ꎮ�̏����i��ԖڂɎw�肵���A�j���[�V�������ҋ@�A�j���[�V�����ƂȂ�j
	m_animationManagerPtr = std::make_unique<AnimationManager>();
	m_animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Hero/Idle.png", 11, 11, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE, 6, true));		//�E�O
	m_animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Hero/Run.png", 8, 8, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE, 4, true));			//�E�P
	m_animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Hero/Jump.png", 4, 4, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE, 8, false));		//�E�Q
	m_animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Hero/Attack.png", 6, 6, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE, 6, false, 1));	//�E�R
	m_animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Hero/Dash.png", 4, 4, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE, 4, false, 2));	//�E�S
}

ColliderID Player::getColliderHolderID() {
	return ColliderID::Player;
}

void Player::setup() {
	if (collider->checkFalling()) {
		//�E�������x�v�Z
		if (m_ySpeed < MAX_FALL_SPEED) m_ySpeed++;
	} else {
		//�E���n
		m_y = GROUND_HEIGHT;
		m_ySpeed = 0;
		m_xSpeed = 0;
		//�E�A�C�h�����
		if (!KeyInput::RIGHT.onPressed() && !KeyInput::LEFT.onPressed()) {
			if (m_animationManagerPtr->change(0)) {
				m_xSpeed = 0;
			}
		}
		//�E���E�ړ�
		if (KeyInput::RIGHT.onPressed()) {
			if (m_animationManagerPtr->change(1)) {
				m_turn = false;
				m_xSpeed = m_baseSpeed;
			}
		}
		if (KeyInput::LEFT.onPressed()) {
			if (m_animationManagerPtr->change(1)) {
				m_turn = true;
				m_xSpeed = -m_baseSpeed;
			}
		}
		//�E�W�����v
		if (KeyInput::Z.onPressedOnce()) {
			if (m_animationManagerPtr->change(2)) {
				m_ySpeed = -12;
			}
		}
		//�E�o�b�N�X�e�b�v
		if (KeyInput::LSHIFT.onPressedOnce()) {
			if (m_animationManagerPtr->change(4)) {
				m_xSpeed = (m_turn ? m_baseSpeed : -m_baseSpeed) * 5;
				m_ySpeed = -5;
			}
		}
	}
	//�E�U��
	if (KeyInput::X.onPressedOnce()) {
		if (m_animationManagerPtr->change(3)) {
			if (!collider->checkFalling()) {
				//�E�n��ōU�������ꍇ�͑����Ɉړ���~
				m_xSpeed = 0;
			}
		}

	}
}