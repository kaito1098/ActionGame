#pragma once
#include <memory>
#include "IColliderHolder.h"

/** @brief �����蔻��̊��N���X */
class BaseCollider {
protected:
    /**
     * @brief �R���X�g���N�^
     * @param (holderPtr) �����蔻���ێ�����I�u�W�F�N�g�̃|�C���^
     * @param (dx) �����蔻���ێ�����I�u�W�F�N�g����̑��΍��W�ix�������j
     * @param (dy) �����蔻���ێ�����I�u�W�F�N�g����̑��΍��W�iy�������j
     */
    BaseCollider(IColliderHolder* holderPtr, int dx, int dy);

    /**
     * @brief �y���z�֐��z�f�X�g���N�^
     */
    virtual ~BaseCollider() = default;

    /** @brief �����蔻���ێ�����I�u�W�F�N�g���w���|�C���^ */
    IColliderHolder* m_holderPtr;

    /** @brief �����蔻���ێ�����I�u�W�F�N�g����̑��΍��W�ix�������j */
    int m_dx;

    /** @brief �����蔻���ێ�����I�u�W�F�N�g����̑��΍��W�iy�������j */
    int m_dy;

    /**
     * @brief �y���z�֐��z�}�b�v�n�`�Ƃ̓����蔻��
     * @param (arg) 
     * @return �߂�l�̐���
     */
    virtual bool isCollide() = 0;

    /**
     * @�y���z�֐��zbrief �������Ă��邩�ǂ����i���n���Ă��邩�ǂ����j
     * @return true�F�������Ă���Afalse�F�������Ă��Ȃ�
     */
    virtual bool checkFalling() = 0;
};