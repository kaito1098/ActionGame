#include "Common.h"

const int SPRITES_X_SIZE = 450;
const int SPRITES_Y_SIZE = 450;

//・自律移動（TODO：テスト用なのであとで消す）
int frameCnt = 0;
int step = 0;

EnemyMushroom::EnemyMushroom(int _x, int _y) :
	IActor(_x, _y, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE) {
	//・TODO：同じキャラクターが複数存在したら、アニメーションのスプライト画像は同じものを使いまわしたい。
	//・使用するアニメーション一式の準備（一番目に指定したアニメーションが待機アニメーションとなる）
	m_animationManagerPtr = std::make_unique<AnimationManager>();
	m_animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Mushroom/Idle.png", 4, 4, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE, 12, true));		//・０
	m_animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Mushroom/Run.png", 8, 8, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE, 4, true));			//・１
	m_animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Mushroom/TakeHit.png", 4, 4, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE, 6, false));	//・２
	m_animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Mushroom/Attack2.png", 8, 8, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE, 6, false, 1));	//・３
}

void EnemyMushroom::setup() {
	frameCnt++;
	if (frameCnt % 120 == 0) {
		switch (step) {
		case 0:
			if (m_animationManagerPtr->change(0)) {
				m_xSpeed = 0;
			}
			step = 1;
			break;
		case 1:
			if (m_animationManagerPtr->change(1)) {
				m_turn = true;
				m_xSpeed = -m_baseSpeed;
			}
			step = 2;
			break;
		case 2:
			if (m_animationManagerPtr->change(0)) {
				m_xSpeed = 0;
			}
			step = 3;
			break;
		default:
			if (m_animationManagerPtr->change(1)) {
				m_turn = false;
				m_xSpeed = m_baseSpeed;
			}
			step = 0;
		}
	}
}