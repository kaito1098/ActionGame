#include "Player.h"
#include "Common.h"
#include "KeyInput.h"

/**
 * @brief �v���C���[�L�����N�^�[�N���X�̃R���X�g���N�^
 * @param _x�F�����ʒu�ix���W�j
 * @param _y�F�����ʒu�iy���W�j
 */
Player::Player(int _x, int _y) :
	x(_x), y(_y), speed(2), xSpeed(0), ySpeed(0), turn(false) {
	//�E�g�p����A�j���[�V�����ꎮ�̏����i��ԖڂɎw�肵���A�j���[�V�������f�t�H���g�A�j���[�V�����ƂȂ�j
	animationManagerPtr = std::make_shared<AnimationManager>();
	animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Hero/Idle.png", 11, 11, 1, 140, 140, 6, true));		//�E�O
	animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Hero/Run.png", 8, 8, 1, 140, 140, 4, true));			//�E�P
	animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Hero/Jump.png", 4, 4, 1, 140, 140, 8, false));			//�E�Q
	animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Hero/Attack.png", 6, 6, 1, 140, 140, 6, false, 1));	//�E�R
	animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Hero/Dash.png", 4, 4, 1, 140, 140, 4, false, 2));		//�E�S
}

void Player::update() {
	if (checkFalling()) {
		//�E�������x�v�Z
		if (ySpeed < 10) ySpeed++;
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
				turn = false;
				xSpeed = speed;
				animationManagerPtr->change(1);
			}
			if (KeyInput::LEFT.onPressed()) {
				turn = true;
				xSpeed = -speed;
				animationManagerPtr->change(1);
			}
			//�E�W�����v
			if (KeyInput::Z.onPressedOnce()) {
				ySpeed = -12;
				animationManagerPtr->change(2);
			}
			//�E�A�C�h�����
			if (!KeyInput::RIGHT.onPressed() && !KeyInput::LEFT.onPressed()) {
				xSpeed = 0;
				animationManagerPtr->change(0);
			}
		}
		//�E�o�b�N�X�e�b�v�i�r�W�[���x���Q�j
		if (animationManagerPtr->getBusyLevel() <= 2) {
			if (KeyInput::LSHIFT.onPressedOnce()) {
				xSpeed = (turn ? speed : -speed) * 5;
				ySpeed = -5;
				animationManagerPtr->change(4);
			}
		}
	}
	//�E�U���i�r�W�[���x���P�j
	if (animationManagerPtr->getBusyLevel() <= 1) {
		if (KeyInput::X.onPressedOnce()) {
			if (!checkFalling()) {
				//�E�n��ōU�������ꍇ�͑����Ɉړ���~
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
	//TODO�F���ۂɂ͂ǂ����肷�ׂ����H
	return y < (SCREEN_HEIGHT / 2);
}