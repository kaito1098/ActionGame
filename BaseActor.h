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
     * @brief �ʒu���A�A�j���[�V�����Ȃǂ̍X�V����
     */
    void update();

    /**
     * @brief ���݂̏�ԂɊ�Â����`�揈��
     */
    void draw();

protected:
    /** @brief �`����W�ix���j */
    int x;

    /** @brief �`����W�iy���j */
    int y;

    /** @brief ��ƂȂ�ړ��X�s�[�h */
    int speed;

    /** @brief �P�t���[��������̈ړ������ix���j */
    int xSpeed;

    /** @brief �P�t���[��������̈ړ������iy���j */
    int ySpeed;

    /** @brief �摜�̉����i�s�N�Z���j */
    int xSize;

    /** @brief �摜�̏c���i�s�N�Z���j */
    int ySize;

    /** @brief ���E���]�`��t���O�itrue�F�E�����Afalse�F�������j */
    bool turn;

    /** @brief �A�j���[�V�����}�l�[�W���ւ̃|�C���^ */
    std::unique_ptr<AnimationManager> animationManagerPtr;

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