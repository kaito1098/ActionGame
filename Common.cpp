#include "Common.h"

//�E�Q�[���S�̂̊Ǘ��p�N���X
std::unique_ptr<GameManager> gameManagerPtr = std::make_unique<GameManager>();

//�E��ʉ𑜓x
const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 900;

//�E�����ʂ̒�`
const int MAX_FALL_SPEED = 8;

//�E�n�ʂ̍����iTODO�F�e�X�g�p�Ȃ̂ł��Ƃŏ����j
const int GROUND_HEIGHT = SCREEN_HEIGHT + 36;