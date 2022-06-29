#include "BaseActor.h"
#include "Common.h"

/**
 * @brief �v���C���[�L�����N�^�[�N���X�̃R���X�g���N�^
 * @param _x�F�����ʒu�ix���W�j
 * @param _y�F�����ʒu�iy���W�j
 */
BaseActor::BaseActor(int _x, int _y, int _speed, int _xSize, int _ySize) :
	x(_x), y(_y), speed(_speed), xSize(_xSize), ySize(_ySize), xSpeed(0), ySpeed(0), turn(false) {
}

//�E�ړ��ʂ̔��f�A�A�j���[�V�����̃A�b�v�f�[�g
void BaseActor::update() {
	setup();
	x += xSpeed;
	y += ySpeed;
	animationManagerPtr->update();
}

//�E�`��
void BaseActor::draw() {
	animationManagerPtr->draw(x - xSize / 2, y - ySize / 2, turn);
}

//�E�󒆂ɂ��邩�ǂ����H
bool BaseActor::checkFalling() {
	//TODO�F���ۂɂ͂ǂ����肷�ׂ����H
	return y < (SCREEN_HEIGHT / 2);
}