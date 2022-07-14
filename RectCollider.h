#pragma once
#include "BaseCollider.h"

/** @brief ��`�̓����蔻��N���X */
class RectCollider : public BaseCollider {
public:
    /** @brief ��`���m�̏Փ˔��� */
    bool isCollide(std::shared_ptr<RectCollider> target);
    
    /** @brief �}�b�v�n�`�Ƃ̏Փ˔��� */
    bool isCollide() override;

private:
    /** @brief ��`�̉��� */
    int width;

    /** @brief ��`�̏c�� */
    int height;

    /** @brief ��ӂ�y���W */
    int top();

    /** @brief ���ӂ�y���W */
    int bottom();

    /** @brief ���ӂ�x���W */
    int left();

    /** @brief �E�ӂ�y���W */
    int right();
};