#pragma once
#include <memory>
#include "GameManager.h"

//�E���O�錾
class GameManager;

//�ETODO�F�Q�[���}�l�[�W���N���X�̓V���O���g���p�^�[���Ő݌v���������H
/** @brief �Q�[���}�l�[�W�� */
extern std::unique_ptr<GameManager> gameManagerPtr;

/** @brief ��ʉ𑜓x�ix�������j */
extern const int SCREEN_WIDTH;

/** @brief ��ʉ𑜓x�iy�������j */
extern const int SCREEN_HEIGHT;

/** @brief �ő嗎�����x */
extern const int MAX_FALL_SPEED;

//�ETODO�F�e�X�g�p�Ȃ̂ł��Ƃŏ���
/** @brief �n�ʂ̍��� */
extern const int GROUND_HEIGHT;