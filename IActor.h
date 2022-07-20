#pragma once
#include "IColliderHolder.h"
#include <vector>
#include <memory>

class IColliderHolder;
class AnimationManager;
class ICollider;

/** @brief �A�j���[�V�����ƃR���C�_�[��ێ�����L�����N�^�[�̊��N���X */
class IActor : public IColliderHolder {
public:
    /**
     * @brief �R���X�g���N�^
     * @param _x�F�����ʒu�ix���W�j
     * @param _y�F�����ʒu�iy���W�j
     * @param _speed�F�ړ����x
     * @param _xSize�F�摜�̉���
     * @param _ySize�F�摜�̏c��
     */
    IActor(int x, int y, int speed, int xSize, int ySize);

    /**
     * @brief �y���z�֐��z�f�X�g���N�^
     */
    virtual ~IActor() = default;

    /**
     * @brief �ʒu���A�A�j���[�V�����Ȃǂ̍X�V����
     */
    void update();

    /**
     * @brief ���݂̏�ԂɊ�Â����`�揈��
     * @param (screenX) �X�N���[�����W�ix�������j
     * @param (screenY) �X�N���[�����W�iy�������j
     */
    void draw(int screenX, int screenY);

    /**
     * @brief �`����W�ix���j�̃Q�b�^�[
     * @return �`����W�ix���j
     */
    int getX() override;

    /**
     * @brief �`����W�iy���j�̃Q�b�^�[
     * @return �`����W�iy���j
     */
    int getY() override;

protected:
    /** @brief �`����W�ix���j */
    int m_x;

    /** @brief �`����W�iy���j */
    int m_y;

    /** @brief ��ƂȂ�ړ��X�s�[�h */
    int m_baseSpeed;

    /** @brief �P�t���[��������̈ړ������ix���j */
    int m_xSpeed;

    /** @brief �P�t���[��������̈ړ������iy���j */
    int m_ySpeed;

    /** @brief �摜�̉��� */
    int m_xSize;

    /** @brief �摜�̏c�� */
    int m_ySize;

    /** @brief ���E���]�`��t���O�itrue�F�E�����Afalse�F�������j */
    bool m_turn;

    /** @brief �������t���O�itrue�F�������ł���Afalse�F�������łȂ��j */
    bool m_falling;

    /** @brief �A�j���[�V�����}�l�[�W���ւ̃|�C���^ */
    std::unique_ptr<AnimationManager> m_animationManagerPtr;

    /** @brief �����蔻�� */
    std::unique_ptr<ICollider> collider;

    /**
     * @brief �A�N�^�[�̕`��ʒu�� array �w��ɂ��Z�b�g����
     * @param (pos) x���W�Ay���W��v�f�Ɏ��� array
     */
    void setPositionByArray(std::array<int, 2> pos);

    /**
     * @brief �������菈���isetup����Ăяo�����z��j
     * @param (animId) �������̃A�j���[�V����ID
     */
    void fall(int animId);

    /**
     * @brief �y���z�֐��zupdate()���Ă΂��O�̃Z�b�g�A�b�v�i�L�[���͂�AI����ɂ��ړ����x�̌���Ȃǁj
     */
    virtual void setup() = 0;
};