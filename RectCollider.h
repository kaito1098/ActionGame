#pragma once
#include "BaseCollider.h"

/** @brief ��`�̓����蔻��N���X */
class RectCollider : public BaseCollider {
public:
    /**
     * @brief �R���X�g���N�^
     * @param (IColliderHolderPtr) �����蔻���ێ�����I�u�W�F�N�g���w���|�C���^
     * @return �߂�l�̐���
     */
    RectCollider(IColliderHolder* holderPtr, int dx, int dy, int width, int height);

    /** @brief ��`���m�̏Փ˔��� */
    bool isCollide(std::shared_ptr<RectCollider> target);
    
    /** @brief �}�b�v�n�`�Ƃ̏Փ˔��� */
    bool isCollide() override;

    /**
     * @brief �������Ă��邩�ǂ����i���n���Ă��邩�ǂ����j
     * @return true�F�������Ă���Afalse�F�������Ă��Ȃ�
     */
    bool checkFalling() override;

private:
    /** @brief ��`�̉��� */
    int m_width;

    /** @brief ��`�̏c�� */
    int m_height;

    /** @brief ��ӂ�y���W */
    int top();

    /** @brief ���ӂ�y���W */
    int bottom();

    /** @brief ���ӂ�x���W */
    int left();

    /** @brief �E�ӂ�y���W */
    int right();
};