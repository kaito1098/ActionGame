#pragma once
#include "Animation.h"
#include <vector>
#include <memory>

/** @brief ������ Animation �N���X���Ǘ�����}�l�[�W���N���X */
class AnimationManager {
public:
	/**
	 * @brief �R���X�g���N�^
	 */
	AnimationManager();

	/**
	 * @brief �A�j���[�V�����N���X�̓o�^
	 * @param (animPtr) �A�j���[�V�����N���X�̎��̂��w���|�C���^
	 * @details ��ԍŏ��ɒǉ������A�j���[�V�������A�C�h����Ԃ�\���A�j���[�V�����ƂȂ�B
	 */
	void add(std::shared_ptr<Animation> animPtr);

	/**
	 * @brief �Đ�����A�j���[�V������ύX����
	 * @param (idx) �ύX�������A�j���[�V������ ID
	 * @param (force) true �̏ꍇ�A�r�W�[���x���𖳎����ċ����I�ɕύX����i�K��l�Ffalse�j
	 * @return �r�W�[���x�����l�����A�ύX�ɐ��������ꍇ true ��Ԃ�
	 */
	bool change(int idx, bool force = false);

	/**
	 * @brief �Đ����̃A�j���[�V�����N���X�� update() ���Ă�
	 */
	void update();

	/**
	 * @brief �T�v
	 * @param (x) �`��ʒu�ix�������j
	 * @param (y) �`��ʒu�iy�������j
	 * @param (turn) ���E���]�t���O�itrue�F���]�Afalse�F���]�Ȃ��j
	 */
	void draw(int x, int y, bool turn);

private:
	/** @brief �Ǘ��Ώۂ̃A�j���[�V�����N���X���w���|�C���^�̓��I�z�� */
	std::vector<std::shared_ptr<Animation>> animations;

	/** @brief �T�v */
	int currentIdx;
};