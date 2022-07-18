#pragma once
#include "ICollider.h"

/** @brief ��`�̓����蔻��N���X */
class RectCollider : public ICollider {
public:
    /**
     * @brief �R���X�g���N�^
     * @param (IColliderHolderPtr) �����蔻���ێ�����I�u�W�F�N�g���w���|�C���^
     */
    RectCollider(IColliderHolder* holderPtr, ColliderID id, int dx, int dy, int width, int height);

    /**
     * @brief �����蔻��̕`��i�f�o�b�O�p�j
     */
    void draw() override;

    /**
     * @brief ��`�R���C�_�[�Ƃ̓����蔻��
     * @param (target) ����̋�`�R���C�_�[
     * @return true�F�Փ˂��Ă���Afalse�F�Փ˂��Ă��Ȃ�
     */
    bool isCollide(std::shared_ptr<RectCollider> target) override;

    /**
     * @brief �V��Ƃ̓����蔻��
     * @return true�F�Փ˂��Ă���Afalse�F�Փ˂��Ă��Ȃ�
     */
    bool checkPassableOver(int x, int y) override;

    /**
     * @brief ���Ƃ̓����蔻��
     * @return true�F�������Ă���Afalse�F�������Ă��Ȃ�
     */
    bool checkPassableUnder(int x, int y) override;

    /**
     * @brief �ǂƂ̓����蔻��i�������j
     * @return true�F�Փ˂��Ă���Afalse�F�Փ˂��Ă��Ȃ�
     */
    bool checkPassableLeft(int x, int y) override;

    /**
     * @brief �ǂƂ̓����蔻��i�E�����j
     * @return true�F�Փ˂��Ă���Afalse�F�Փ˂��Ă��Ȃ�
     */
    bool checkPassableRight(int x, int y) override;

private:
    /** @brief ��`�̉��� */
    int m_width;

    /** @brief ��`�̏c�� */
    int m_height;

    /** @brief ��ӂ�y���W�i holder �̈ʒu����Ƃ���j */
    int top();

    /** @brief ���ӂ�y���W�i holder �̈ʒu����Ƃ���j */
    int bottom();

    /** @brief ���ӂ�x���W�i holder �̈ʒu����Ƃ���j */
    int left();

    /** @brief �E�ӂ�y���W�i holder �̈ʒu����Ƃ���j */
    int right();
};