#include "Common.h"

const int SPRITES_X_SIZE = 450;
const int SPRITES_Y_SIZE = 152;
//�E�e�p�����[�^
const int BASE_SPEED = 2;   //�E�ړ����x

//�E�����ړ��iTODO�F�e�X�g�p�Ȃ̂ł��Ƃŏ����j
int frameCnt = 0;
int step = 0;

EnemyMushroom::EnemyMushroom(int _x, int _y) :
    IActor(_x, _y, BASE_SPEED, SPRITES_X_SIZE, SPRITES_Y_SIZE) {
    //�E�����蔻��
    collider = std::make_unique<RectCollider>(this, ColliderID::Enemy, 185, 32, 80, 120);
    //�ETODO�F�����L�����N�^�[���������݂�����A�A�j���[�V�����̃X�v���C�g�摜�͓������̂��g���܂킵�����B
    //�E�g�p����A�j���[�V�����ꎮ�̏����i��ԖڂɎw�肵���A�j���[�V�������ҋ@�A�j���[�V�����ƂȂ�j
    m_animationManagerPtr = std::make_unique<AnimationManager>();
    m_animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Mushroom/Idle.png", 4, 4, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE, 12, true));		//�E�O
    m_animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Mushroom/Run.png", 8, 8, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE, 4, true));			//�E�P
    m_animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Mushroom/TakeHit.png", 4, 4, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE, 6, false));	//�E�Q
    m_animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Mushroom/Attack2.png", 8, 8, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE, 6, false, 1));	//�E�R
}

void EnemyMushroom::setup() {
    if (collider->checkPassableUnder(m_x, m_y)) {
        //�E����
        if (!m_falling) {
            m_falling = true;
            m_xSpeed = 0;
            m_animationManagerPtr->change(0);
        }
        if (m_ySpeed < MAX_FALL_SPEED) m_ySpeed += GRAVITY;
    } else {
        if (m_falling) {
            //�E���n
            m_falling = false;
            m_y = collider->getFloorY(m_x, m_y);
            m_xSpeed = 0;
            m_ySpeed = 0;
        }
    }
    frameCnt++;
    switch (step) {
    case 0:
        if (m_animationManagerPtr->change(0)) {
            m_xSpeed = 0;
        }
        if (frameCnt % 120 == 0) step = 1;
        break;
    case 1:
        if (m_animationManagerPtr->change(1)) {
            m_turn = true;
            m_xSpeed = -m_baseSpeed;
        }
        if (!collider->checkPassableLeft(m_x + m_xSpeed, m_y)) m_xSpeed = 0;
        if (frameCnt % 120 == 0) step = 2;
        break;
    case 2:
        if (m_animationManagerPtr->change(0)) {
            m_xSpeed = 0;
        }
        if (frameCnt % 120 == 0) step = 3;
        break;
    default:
        if (m_animationManagerPtr->change(1)) {
            m_turn = false;
            m_xSpeed = m_baseSpeed;
        }
        if (!collider->checkPassableRight(m_x + m_xSpeed, m_y)) m_xSpeed = 0;
        if (frameCnt % 120 == 0) step = 0;
    }
}