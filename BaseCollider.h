#pragma once
#include <memory>
#include "BaseActor.h"

/** @brief �����蔻��̊��N���X */
template <class T>
class BaseCollider {
protected:
    /**
     * @brief �R���X�g���N�^
     * @param (holderPtr) �����蔻���ێ�����I�u�W�F�N�g�̃|�C���^
     * @param (dx) �����蔻���ێ�����I�u�W�F�N�g����̑��΍��W�ix�������j
     * @param (dy) �����蔻���ێ�����I�u�W�F�N�g����̑��΍��W�iy�������j
     */
    BaseCollider(std::shared_ptr<T> holderPtr, int dx, int dy);

    /**
     * @brief �y���z�֐��z�f�X�g���N�^
     */
    virtual ~BaseCollider() = default;

    /** @brief Collider ��ێ����� Actor �N���X���w���|�C���^ */
    std::shared_ptr<T> m_holderPtr;

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
};