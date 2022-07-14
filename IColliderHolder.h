#pragma once
#include "Common.h"

/** @brief �R���C�_�[��ێ�����I�u�W�F�N�g�p�C���^�[�t�F�[�X */
class IColliderHolder {
public:
    /**
     * @brief �y���z�֐��zColliderHolderID �̃Q�b�^�[
     * @return ColliderHolderID
     */
    virtual ColliderID getColliderHolderID() = 0;

    /**
     * @brief �y���z�֐��z�`����W�ix���j�̃Q�b�^�[
     * @return �`����W�ix���j
     */
    virtual int getX() = 0;

    /**
     * @brief �y���z�֐��z�`����W�iy���j�̃Q�b�^�[
     * @return �`����W�iy���j
     */
    virtual int getY() = 0;
};