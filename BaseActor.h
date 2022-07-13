#pragma once
#include "AnimationManager.h"
#include <vector>
#include <memory>

/** @brief �A�j���[�V�����ƃR���W������ێ�����L�����N�^�[�̊��N���X */
class BaseActor {
public:
    /**
     * @brief �R���X�g���N�^
     * @param _x�F�����ʒu�ix���W�j
     * @param _y�F�����ʒu�iy���W�j
     * @param _speed�F�ړ����x
     * @param _xSize�F�摜�̉���
     * @param _ySize�F�摜�̏c��
     */
    BaseActor(int x, int y, int speed, int xSize, int ySize);

    /**
     * @brief �y���z�֐��z�f�X�g���N�^
     */
    virtual ~BaseActor() = default;

    /**
     * @brief �ʒu���A�A�j���[�V�����Ȃǂ̍X�V����
     */
    void update();

    /**
     * @brief ���݂̏�ԂɊ�Â����`�揈��
     */
    void draw();

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

    /** @brief �A�j���[�V�����}�l�[�W���ւ̃|�C���^ */
    std::unique_ptr<AnimationManager> m_animationManagerPtr;

    /**
     * @brief �������Ă��邩�ǂ����i���n���Ă��邩�ǂ����j
     * @return true�F�������Ă���Afalse�F�������Ă��Ȃ�
     */
    bool checkFalling();

    /**
     * @brief �y���z�֐��zupdate()���Ă΂��O�̃Z�b�g�A�b�v�i�L�[���͂�AI����ɂ��ړ����x�̌���Ȃǁj
     */
    virtual void setup() = 0;
};