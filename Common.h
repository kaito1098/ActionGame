#pragma once
#include <memory>

//�E���O�錾
class GameManager;

/** @brief ��ʉ𑜓x�ix�������j */
extern const int SCREEN_WIDTH;

/** @brief ��ʉ𑜓x�iy�������j */
extern const int SCREEN_HEIGHT;

/** @brief �ő嗎�����x */
extern const int MAX_FALL_SPEED;

//�ETODO�F�e�X�g�p�Ȃ̂ł��Ƃŏ���
/** @brief �n�ʂ̍��� */
extern const int GROUND_HEIGHT;

/** @brief �}�b�v�����蔻���ʁi�񋓑сj */
enum class MapCollideID {
    passable = 0,
    impassable = 1,
    jumpPassable = 2,
    squatPassable = 3,
    rightStair = 4,
    leftStair = 5,
};

/** @brief �����蔻���ʁi�񋓑сj */
enum class ColliderID {
    Player = 0,
    Enemy = 1,
};