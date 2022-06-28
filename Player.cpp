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
	animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Hero/Attack.png", 6, 6, 1, 140, 140, 6, false, true));	//�E�R
}

void Player::update() {
	if (!animationManagerPtr->isBusy()) {
		if (checkFalling()) {
			//�E�������x�v�Z
			if (ySpeed < 10) ySpeed++;
		} else {
			//�E���Ԓ��łȂ���΃L�[����ɂ�鐧��
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
		//�E���n
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
	//TODO�F���ۂɂ͂ǂ����肷�ׂ����H
	return y < (SCREEN_HEIGHT / 2);
}