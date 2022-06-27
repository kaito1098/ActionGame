#include "Player.h"
#include "KeyInput.h"

/**
 * @brief �v���C���[�L�����N�^�[�N���X�̃R���X�g���N�^
 * @param _x�F�����ʒu�ix���W�j
 * @param _y�F�����ʒu�iy���W�j
 */
Player::Player(int _x, int _y) :
	x(_x), y(_y), turn(false)
{
	//�E�g�p����A�j���[�V�����ꎮ�̏����i��ԖڂɎw�肵���A�j���[�V�������f�t�H���g�A�j���[�V�����ƂȂ�j
	animationManagerPtr = std::make_shared<AnimationManager>();
	animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Hero/Idle.png", 11, 11, 1, 140, 140, 6, true));	//�E�O
	animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Hero/Run.png", 8, 8, 1, 140, 140, 4, true));		//�E�P
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