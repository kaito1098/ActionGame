#pragma once

/**
 * @brief �L�[���͂Ɋւ���@�\���܂Ƃ߂��N���X
 * @details ��{�I�ɂ� namespace KeyInput �ɂĒ�`���ꂽ���̂𗘗p���邱�ƁB
 */
class KeyInputUtility {
public:
	/** @brief �R���X�g���N�^ */
	KeyInputUtility(int keyCode);

	/**
	 * @brief �L�[��������Ă��邩�H�i�`���^�����O�l���Ȃ��j
	 * @return true�F������Ă���Afalse�F������Ă��Ȃ�
	 * @details ������Ă���ԁA���t���[�� true ��ԋp��������
	 */
	bool onPressed();

	/**
	 * @brief �L�[��������Ă��邩�H
	 * @return true�F������Ă���Afalse�F������Ă��Ȃ�
	 * @details �����ꂽ�u�Ԃ̃t���[���̂� true ��ԋp����i���t���[�����肵�Ă���O��j
	 */
	bool onPressedOnce();

private:
	/** @brief ���肷��L�[�R�[�h */
	int keyCode;

	/** @brief ������Ă���t���O */
	bool pressed;
};