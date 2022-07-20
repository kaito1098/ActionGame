#include "Common.h"

//�E�X�v���C�g�摜 1 �R�}���̉摜�T�C�Y
const int SPRITES_X_SIZE = 420;
const int SPRITES_Y_SIZE = 200;
//�E�e�p�����[�^
const int BASE_SPEED = 6;   //�E�ړ����x
const int JUMP_FORCE = 28;	//�E�W�����v��

Player::Player(int _x, int _y) :
    IActor(_x, _y, BASE_SPEED, SPRITES_X_SIZE, SPRITES_Y_SIZE) {
    //�E�����蔻��
    collider = std::make_unique<RectCollider>(this, ColliderID::Player, 160, 80, 100, 120);
    //�E�g�p����A�j���[�V�����ꎮ�̏����i��ԖڂɎw�肵���A�j���[�V�������ҋ@�A�j���[�V�����ƂȂ�j
    m_animationManagerPtr = std::make_unique<AnimationManager>();
    m_animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Hero/Idle.png", 11, 11, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE, 6, true));		//�E�O
    m_animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Hero/Run.png", 8, 8, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE, 4, true));			//�E�P
    m_animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Hero/Jump.png", 4, 4, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE, 8, true));		    //�E�Q
    m_animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Hero/Attack.png", 6, 6, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE, 4, false, 1));	//�E�R
    m_animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Hero/Dash.png", 4, 4, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE, 4, false, 2));		//�E�S
}

std::array<int, 2> Player::getCenterPosition() {
    int x = m_x + SPRITES_X_SIZE / 2;
    int y = m_y + SPRITES_Y_SIZE / 2;
    return std::array<int, 2>{x, y};
}

void Player::setup() {
    fall(2);
    //�E�A�C�h�����
    if (!KeyInput::RIGHT->onPressed() && !KeyInput::LEFT->onPressed()) {
        if (!m_falling) {
            if (m_animationManagerPtr->change(0)) {
                m_xSpeed = 0;
            }
        } else {
            //�E�������͑��x�ύX�̂�
            m_xSpeed = 0;
        }
    }
    //�E���E�ړ�
    if (KeyInput::RIGHT->onPressed()) {
        if (!m_falling) {
            if (m_animationManagerPtr->change(1)) {
                m_turn = false;
                m_xSpeed = m_baseSpeed;
            }
        } else {
            //�E�������͏�ɍ��E�ړ��\
            m_xSpeed = m_baseSpeed;
        }
        if (!collider->checkPassableRight(m_x + m_xSpeed, m_y)) m_xSpeed = 0;
    }
    if (KeyInput::LEFT->onPressed()) {
        if (!m_falling) {
            if (m_animationManagerPtr->change(1)) {
                m_turn = true;
                m_xSpeed = -m_baseSpeed;
            }
        } else {
            //�E�������͏�ɍ��E�ړ��\
            m_xSpeed = -m_baseSpeed;
        }
        if (!collider->checkPassableLeft(m_x + m_xSpeed, m_y)) m_xSpeed = 0;
    }
    //�E�W�����v
    if (KeyInput::Z->onPressedOnce()) {
        if (!m_falling) {
            if (m_animationManagerPtr->change(2)) {
                m_ySpeed = -JUMP_FORCE;
            }
        }
    }
    //�E�o�b�N�X�e�b�v
    if (KeyInput::LSHIFT->onPressedOnce()) {
        if (!m_falling && m_animationManagerPtr->change(4)) {
            m_xSpeed = (m_turn ? m_baseSpeed : -m_baseSpeed) * 5;
        }
    }
    //�E�U��
    if (KeyInput::X->onPressedOnce()) {
        if (m_animationManagerPtr->change(3)) {
            if (!m_falling) {
                //�E�n��ōU�������ꍇ�A�A�N�V�����I���܂ňړ��֎~
                m_xSpeed = 0;
            }
        }
    }
}