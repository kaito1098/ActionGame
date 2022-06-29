#include "EnemyMushroom.h"
#include "Common.h"

const int SPRITES_X_SIZE = 150;
const int SPRITES_Y_SIZE = 150;

//�E�����ړ��iTODO�F�e�X�g�p�Ȃ̂ł��Ƃŏ����j
int frameCnt = 0;
int step = 0;

/**
 * @brief �v���C���[�L�����N�^�[�N���X�̃R���X�g���N�^
 * @param _x�F�����ʒu�ix���W�j
 * @param _y�F�����ʒu�iy���W�j
 */
EnemyMushroom::EnemyMushroom(int _x, int _y) :
	BaseActor(_x, _y, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE) {
	//�E�g�p����A�j���[�V�����ꎮ�̏����i��ԖڂɎw�肵���A�j���[�V�������ҋ@�A�j���[�V�����ƂȂ�j
	animationManagerPtr = std::make_shared<AnimationManager>();
	animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Mushroom/Idle.png", 4, 4, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE, 12, true));		//�E�O
	animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Mushroom/Run.png", 8, 8, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE, 4, true));			//�E�P
	animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Mushroom/TakeHit.png", 4, 4, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE, 6, false));	//�E�Q
	animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Mushroom/Attack2.png", 8, 8, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE, 6, false, 1));	//�E�R
}

//�E�L�[���͂ɂ�鑀��A�A�j���[�V�����J�ڂƈړ��ʂ̃Z�b�g�Ȃ�
void EnemyMushroom::setup() {
	frameCnt++;
	if (frameCnt % 120 == 0) {
		switch (step) {
		case 0:
			if (animationManagerPtr->change(0)) {
				xSpeed = 0;
			}
			step = 1;
			break;
		case 1:
			if (animationManagerPtr->change(1)) {
				turn = true;
				xSpeed = -speed;
			}
			step = 2;
			break;
		case 2:
			if (animationManagerPtr->change(0)) {
				xSpeed = 0;
			}
			step = 3;
			break;
		default:
			if (animationManagerPtr->change(1)) {
				turn = false;
				xSpeed = speed;
			}
			step = 0;
			break;
		}
	}
}