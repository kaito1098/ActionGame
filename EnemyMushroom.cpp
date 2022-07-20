#include "Common.h"

const int SPRITES_X_SIZE = 450;
const int SPRITES_Y_SIZE = 152;
//・各パラメータ
const int BASE_SPEED = 2;   //・移動速度

//・自律移動（TODO：テスト用なのであとで消す）
int frameCnt = 0;
int step = 0;

EnemyMushroom::EnemyMushroom(int _x, int _y) :
    IActor(_x, _y, BASE_SPEED, SPRITES_X_SIZE, SPRITES_Y_SIZE) {
    //・当たり判定
    collider = std::make_unique<RectCollider>(this, ColliderID::Enemy, 185, 32, 80, 120);
    //・TODO：同じキャラクターが複数存在したら、アニメーションのスプライト画像は同じものを使いまわしたい。
    //・使用するアニメーション一式の準備（一番目に指定したアニメーションが待機アニメーションとなる）
    m_animationManagerPtr = std::make_unique<AnimationManager>();
    m_animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Mushroom/Idle.png", 4, 4, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE, 12, true));		//・０
    m_animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Mushroom/Run.png", 8, 8, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE, 4, true));			//・１
    m_animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Mushroom/TakeHit.png", 4, 4, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE, 6, false));	//・２
    m_animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Mushroom/Attack2.png", 8, 8, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE, 6, false, 1));	//・３
}

void EnemyMushroom::setup() {
    if (collider->checkPassableUnder(m_x, m_y)) {
        //・落下
        if (!m_falling) {
            m_falling = true;
            m_xSpeed = 0;
            m_animationManagerPtr->change(0);
        }
        if (m_ySpeed < MAX_FALL_SPEED) m_ySpeed += GRAVITY;
    } else {
        if (m_falling) {
            //・着地
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