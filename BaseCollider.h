#pragma once
#include <memory>
#include "BaseActor.h"

/** @brief �����蔻��̊��N���X */
template <class T>
class BaseCollider {
protected:
    /** @brief �R���X�g���N�^ */
    BaseCollider(std::shared_ptr<T> holder, int dx, int dy);

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