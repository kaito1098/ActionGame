#pragma once
#include <memory>

class GameManager;
class IColliderHolder;
class RectCollider;

/** @brief �����蔻��̊��N���X */
class ICollider {
public:
    /**
     * @brief �R���X�g���N�^
     * @param (holderPtr) �����蔻���ێ�����I�u�W�F�N�g�̃|�C���^
     * @param (dx) �����蔻���ێ�����I�u�W�F�N�g����̑��΍��W�ix�������j
     * @param (dy) �����蔻���ێ�����I�u�W�F�N�g����̑��΍��W�iy�������j
     */
    ICollider(IColliderHolder* holderPtr, int dx, int dy);

    /**
     * @brief �y���z�֐��z�f�X�g���N�^
     */
    virtual ~ICollider() = default;

    /**
     * @brief �y���z�֐��z�����蔻��̕`��i�f�o�b�O�p�j
     */
    virtual void draw() = 0;

    /**
     * @brief �y���z�֐��z��`�R���C�_�[�Ƃ̓����蔻��
     * @param (target) ����̋�`�R���C�_�[
     * @return true�F�Փ˂��Ă���Afalse�F�Փ˂��Ă��Ȃ�
     */
    virtual bool isCollide(std::shared_ptr<RectCollider> target) = 0;

    /**
     * @brief �y���z�֐��z�}�b�v�n�`�Ƃ̓����蔻��
     * @return true�F�Փ˂��Ă���Afalse�F�Փ˂��Ă��Ȃ�
     */
    virtual bool isCollide() = 0;

    /**
     * @�y���z�֐��zbrief �������Ă��邩�ǂ����i���n���Ă��邩�ǂ����j
     * @return true�F�������Ă���Afalse�F�������Ă��Ȃ�
     */
    virtual bool isFalling() = 0;
    
    /** @brief �����蔻���ێ�����I�u�W�F�N�g���w���|�C���^ */
    IColliderHolder* m_holderPtr;

protected:
    /** @brief �����蔻���ێ�����I�u�W�F�N�g����̑��΍��W�ix�������j */
    int m_dx;

    /** @brief �����蔻���ێ�����I�u�W�F�N�g����̑��΍��W�iy�������j */
    int m_dy;
};