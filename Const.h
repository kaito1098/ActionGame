#pragma once
#include <memory>

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
    passable = 0,       //�E�ʍs�\
    impassable = 1,     //�E�ʍs�s�\
    jumpPassable = 2,   //�E�W�����v�ŉ�����ʍs�\
    squatPassable = 3,  //�E���Ⴊ�݂y�ŏォ��ʍs�\
    rightStair = 4,     //�E�E�オ��K�i
    leftStair = 5,      //�E���オ��K�i
};

/** @brief �����蔻���ʁi�񋓑сj */
enum class ColliderID {
    Player = 0,
    Enemy = 1,
};