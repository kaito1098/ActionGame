#pragma once
#include "BaseActor.h"

/** @brief �v���C���[�L�����N�^�[ */
class Player : public BaseActor {
public:
	/**
	 * @brief �R���X�g���N�^
	 * @param _x�F�����ʒu�ix���W�j
	 * @param _y�F�����ʒu�iy���W�j
	 * @remark �A�j���[�V�����̓o�^�͂����ōs���Ă���B
	 */
	Player(int x, int y);

	/**
	 * @brief ColliderHolderID �̃Q�b�^�[
	 * @return ColliderHolderID
	 */
	ColliderID getColliderHolderID();

protected:
	/**
	 * @brief �L�[���͂ɂ�鑀��̎���
	 * @remark �\���L�[�ňړ� TODO�F2�񉟂��ƃ��[�����O
	 * @remark Z�L�[�ŃW�����v
	 * @remark X�L�[�ōU��
	 * @remark LShift�L�[�Ńo�b�N�X�e�b�v
	 */
	void setup() override;
};