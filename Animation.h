#pragma once
#include <vector>
#include <string>

/** @brief ��̃X�v���C�g�摜���Ǘ�����A�j���[�V�����N���X */
class Animation {
public:
	/**
	 * @brief �R���X�g���N�^
	 */
	Animation(std::string filePath, int allNum, int xNum, int yNum, int xSize, int ySize, int animFrameCnt, bool enabledLoop, int busyLevel = 0);

	/**
	 * @brief �K�v�ɉ����ăX�v���C�g�摜�̃R�}����i�߂�
	 * @return true�F�Ō�̃R�}�܂ŃA�j���[�V���������������Afalse�F����ȊO�i���[�v�L�����͏��false�j
	 */
	bool update();

	/**
	 * @brief �A�j���[�V�������Đ�������ԂɃ��Z�b�g����
	 */
	void reset();

	/**
	 * @brief ���݂̃X�v���C�g�摜�̂P�R�}�̉摜�n���h�����擾����
	 * @return ���݃t���[���ŕ`�悷�ׂ��摜�n���h��
	 */
	int getGraphHandle();

	/**
	 * @brief �r�W�[���x�����擾����
	 * @return ���݂̃A�j���[�V�����̃r�W�[���x��
	 * @details �r�W�[���x���Ƃ�
	 * @details �A�j���[�V�����i�A�N�V�����j���Ƃ̗D��x���Ǘ����邽�߂̒l�B
	 * @details �r�W�[���x���̍����A�j���[�V�����Đ����́A���r�W�[���x���̒Ⴂ�A�j���[�V�����͊��荞��ōĐ��ł��Ȃ��B
	 * @details �i��F�W�����v���i�r�W�[���x���P�j�́A���E�Ɉړ����Ă����s�A�j���[�V�����i�r�W�[���x���O�j���Đ����Ȃ��j
	 */
	int getBusyLevel();

private:
	/** @brief �X�v���C�g�摜�̃n���h���i�������ꂽ�摜�������̓��I�z��j */
	std::vector<int> sprites;

	/** @brief sprites[] ���猻�݂̃R�}���w�肷�邽�߂̃C���f�b�N�X */
	int spritesIdx;

	/** @brief �X�v���C�g�摜�̕������� */
	int allNum;

	/** @brief �X�v���C�g�摜�̕������ix�������j */
	int xNum;

	/** @brief �X�v���C�g�摜�̕������iy�������j */
	int yNum;

	/** @brief �摜�P�R�}������̉����i�s�N�Z���j */
	int xSize;

	/** @brief �摜�P�R�}������̏c���i�s�N�Z���j */
	int ySize;

	/** @brief �A�j���[�V�����Đ��J�n���疈�t���[���C���N�������g����l */
	int frameCnt;

	/** @brief ���t���[�����ƂɎ��̃X�v���C�g�摜�̃R�}�ɐi�߂邩�̒l */
	int animFrameCnt;

	/** @brief ���[�v�Đ��t���O�ifalse�̏ꍇ�A�A�j���[�V���������������玩���I�ɃA�C�h����Ԃɖ߂�z��j */
	bool enabledLoop;

	/** @brief �r�W�[���x���i�ڍׂ� getBusyLevel() ���Q�Ɓj */
	int busyLevel;
};