#include "Player.h"
#include "Common.h"
#include "KeyInput.h"

const int SPRITES_X_SIZE = 140;
const int SPRITES_Y_SIZE = 140;

/**
 * @brief �v���C���[�L�����N�^�[�N���X�̃R���X�g���N�^
 * @param _x�F�����ʒu�ix���W�j
 * @param _y�F�����ʒu�iy���W�j
 */
Player::Player(int _x, int _y) :
	BaseActor(_x, _y, 2, SPRITES_X_SIZE, SPRITES_Y_SIZE) {
	//�E�g�p����A�j���[�V�����ꎮ�̏����i��ԖڂɎw�肵���A�j���[�V�������ҋ@�A�j���[�V�����ƂȂ�j
	animationManagerPtr = std::make_shared<AnimationManager>();
	animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Hero/Idle.png", 11, 11, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE, 6, true));		//�E�O
	animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Hero/Run.png", 8, 8, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE, 4, true));			//�E�P
	animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Hero/Jump.png", 4, 4, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE, 8, false));		//�E�Q
	animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Hero/Attack.png", 6, 6, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE, 6, false, 1));	//�E�R
	animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Hero/Dash.png", 4, 4, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE, 4, false, 2));	//�E�S
}

//�E�L�[���͂ɂ�鑀��A�A�j���[�V�����J�ڂƈړ��ʂ̃Z�b�g�Ȃ�
void Player::setup() {
	if (checkFalling()) {
		//�E�������x�v�Z
		if (ySpeed < MAX_FALL_SPEED) ySpeed++;
		//�E���n
		if (y + ySpeed >= SCREEN_HEIGHT / 2) {
			y = SCREEN_HEIGHT / 2;
			ySpeed = 0;
			xSpeed = 0;
		}
	} else {
		//�E�������łȂ��ꍇ�A�r�W�[���x���O�̊e����
		if (animationManagerPtr->getBusyLevel() <= 0) {
			//�E���E�ړ�
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
			//�E�W�����v
			if (KeyInput::Z.onPressedOnce()) {
				if (animationManagerPtr->change(2)) {
					ySpeed = -12;
				}
			}
			//�E�A�C�h�����
			if (!KeyInput::RIGHT.onPressed() && !KeyInput::LEFT.onPressed()) {
				if (animationManagerPtr->change(0)) {
					xSpeed = 0;
				}
			}
		}
		//�E�o�b�N�X�e�b�v
		if (KeyInput::LSHIFT.onPressedOnce()) {
			if (animationManagerPtr->change(4)) {
				xSpeed = (turn ? speed : -speed) * 5;
				ySpeed = -5;
			}
		}
	}
	//�E�U��
	if (KeyInput::X.onPressedOnce()) {
		if (animationManagerPtr->change(3)) {
			if (!checkFalling()) {
				//�E�n��ōU�������ꍇ�͑����Ɉړ���~
				xSpeed = 0;
			}
		}

	}
}