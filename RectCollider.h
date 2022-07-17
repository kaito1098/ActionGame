#pragma once
#include "ICollider.h"

/** @brief ��`�̓����蔻��N���X */
class RectCollider : public ICollider {
public:
    /**
     * @brief �R���X�g���N�^
     * @param (IColliderHolderPtr) �����蔻���ێ�����I�u�W�F�N�g���w���|�C���^
     */
    RectCollider(IColliderHolder* holderPtr, int dx, int dy, int width, int height);

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
     * @brief �}�b�v�n�`�Ƃ̓����蔻��
     * @return true�F�Փ˂��Ă���Afalse�F�Փ˂��Ă��Ȃ�
     */
    std::array<int, 2> checkMapCollide() override;

    /**
     * @�y���z�֐��zbrief ���������ǂ���
     * @return true�F�������Ă���Afalse�F�������Ă��Ȃ�
     */
    bool isFalling() override;

private:
    /** @brief ��`�̉��� */
    int m_width;

    /** @brief ��`�̏c�� */
    int m_height;

    /**
     * @brief ���Ƃ̓����蔻��
     * @return true�F�������Ă���Afalse�F�������Ă��Ȃ�
     */
    bool checkMapCollideFloor(std::shared_ptr<Map> mapPtr, int& x, int& y);

    /**
     * @brief �ǂƂ̓����蔻��i�E�����j
     * @return true�F�Փ˂��Ă���Afalse�F�Փ˂��Ă��Ȃ�
     */
    bool checkMapCollideRight(std::shared_ptr<Map> mapPtr, int& x, int& y);

    /**
     * @brief �V��Ƃ̓����蔻��
     * @return true�F�Փ˂��Ă���Afalse�F�Փ˂��Ă��Ȃ�
     */
    bool checkMapCollideCeiling(std::shared_ptr<Map> mapPtr, int& x, int& y);

    /**
     * @brief �ǂƂ̓����蔻��i�������j
     * @return true�F�Փ˂��Ă���Afalse�F�Փ˂��Ă��Ȃ�
     */
    bool checkMapCollideLeft(std::shared_ptr<Map> mapPtr, int& x, int& y);

    /** @brief ��ӂ�y���W�i holder �̈ʒu����Ƃ���j */
    int top();

    /** @brief ���ӂ�y���W�i holder �̈ʒu����Ƃ���j */
    int bottom();

    /** @brief ���ӂ�x���W�i holder �̈ʒu����Ƃ���j */
    int left();

    /** @brief �E�ӂ�y���W�i holder �̈ʒu����Ƃ���j */
    int right();

    /** @brief ��ӂ�y���W�i�w����W����Ƃ���j */
    int top(int y);

    /** @brief ���ӂ�y���W�i�w����W����Ƃ���j */
    int bottom(int y);

    /** @brief ���ӂ�x���W�i�w����W����Ƃ���j */
    int left(int x);

    /** @brief �E�ӂ�y���W�i�w����W����Ƃ���j */
    int right(int x);
};