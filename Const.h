#pragma once
#include <memory>

/** @brief �f�o�b�O�t���O�i�����蔻��̉����Ȃǁj */
extern const bool DEBUG_FLAG;

/** @brief ��ʉ𑜓x�ix�������j */
extern const int SCREEN_WIDTH;

/** @brief ��ʉ𑜓x�iy�������j */
extern const int SCREEN_HEIGHT;

/** @brief �d�͂ɂ�閈�t���[���̉����x */
extern const int GRAVITY;

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
    rightStair = 3,     //�E�E�オ��K�i
    leftStair = 4,      //�E���オ��K�i
};

/** @brief �����蔻���ʁi�񋓑сj */
enum class ColliderID {
    Player = 0,
    Enemy = 1,
};