#pragma once
#include "IActor.h"

class IActor;

/** @brief �}�b�V�����[�������X�^�[ */
class EnemyMushroom : public IActor {
public:
	/**
	 * @brief �R���X�g���N�^
     * @param _x�F�����ʒu�ix���W�j
     * @param _y�F�����ʒu�iy���W�j
	 * @remark �A�j���[�V�����̓o�^�͂����ōs���Ă���B
	 */
	EnemyMushroom(int x, int y);

protected:
	/**
	 * @brief AI�ɂ�鋓���̎���
	 * @remark ���펞�͈��Ԋu�ō��E�ɜp�j����̂݁B
	 * @remark �v���C���[�����͈͂ɋ߂Â��ƁA�v���C���[�ɋ߂Â��Ă����B
	 * @remark �U���\�͈͂ɂȂ�����U�����[�V�����ɓ���B
	 */
	void setup() override;
};