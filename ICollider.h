#pragma once
#include <memory>
#include <array>

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
    ICollider(IColliderHolder* holderPtr, ColliderID id, int dx, int dy);

    /**
     * @brief �y���z�֐��z�f�X�g���N�^
     */
    virtual ~ICollider() = default;

    /**
     * @brief �y���z�֐��z�����蔻��̕`��i�f�o�b�O�p�j
     * @param (screenX) �X�N���[�����W�ix�������j
     * @param (screenY) �X�N���[�����W�iy�������j
     */
    virtual void draw(int screenX, int screenY) = 0;

    /**
     * @brief �y���z�֐��z��`�R���C�_�[�Ƃ̓����蔻��
     * @param (target) ����̋�`�R���C�_�[
     * @return true�F�Փ˂��Ă���Afalse�F�Փ˂��Ă��Ȃ�
     */
    virtual bool isCollide(std::shared_ptr<RectCollider> target) = 0;

    /**
     * @brief �y���z�֐��z�V��Ƃ̓����蔻��
     * @return true�F�Փ˂��Ă���Afalse�F�Փ˂��Ă��Ȃ�
     */
    virtual bool checkPassableOver(int x, int y) = 0;

    /**
     * @brief �y���z�֐��z���Ƃ̓����蔻��
     * @return true�F�������Ă���Afalse�F�������Ă��Ȃ�
     */
    virtual bool checkPassableUnder(int x, int y) = 0;

    /**
     * @brief �y���z�֐��z�ǂƂ̓����蔻��i�������j
     * @return true�F�Փ˂��Ă���Afalse�F�Փ˂��Ă��Ȃ�
     */
    virtual bool checkPassableLeft(int x, int y) = 0;

    /**
     * @brief �y���z�֐��z�ǂƂ̓����蔻��i�E�����j
     * @return true�F�Փ˂��Ă���Afalse�F�Փ˂��Ă��Ȃ�
     */
    virtual bool checkPassableRight(int x, int y) = 0;

    /**
     * @brief �y���z�֐��z���ɐڂ��邽�߂� y ���W�̒l���擾����
     * @return ���ɐڂ��邽�߂� y ���W�̒l
     */
    virtual int getFloorY(int x, int y) = 0;
    
    /** @brief �����蔻���ێ�����I�u�W�F�N�g���w���|�C���^ */
    IColliderHolder* m_holderPtr;

protected:
    const ColliderID colliderID;

    /** @brief �����蔻���ێ�����I�u�W�F�N�g����̑��΍��W�ix�������j */
    int m_dx;

    /** @brief �����蔻���ێ�����I�u�W�F�N�g����̑��΍��W�iy�������j */
    int m_dy;
};