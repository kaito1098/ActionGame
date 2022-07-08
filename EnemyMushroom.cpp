#include "EnemyMushroom.h"
#include "Common.h"

const int SPRITES_X_SIZE = 450;
const int SPRITES_Y_SIZE = 450;

//・自律移動（TODO：テスト用なのであとで消す）
int frameCnt = 0;
int step = 0;

EnemyMushroom::EnemyMushroom(int _x, int _y) :
	BaseActor(_x, _y, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE) {
	//・TODO：同じキャラクターが複数存在したら、アニメーションのスプライト画像は同じものを使いまわしたい。
	//・使用するアニメーション一式の準備（一番目に指定したアニメーションが待機アニメーションとなる）
	animationManagerPtr = std::make_unique<AnimationManager>();
	animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Mushroom/Idle.png", 4, 4, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE, 12, true));		//・０
	animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Mushroom/Run.png", 8, 8, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE, 4, true));			//・１
	animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Mushroom/TakeHit.png", 4, 4, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE, 6, false));	//・２
	animationManagerPtr->add(std::make_shared<Animation>("Data/Actor/Mushroom/Attack2.png", 8, 8, 1, SPRITES_X_SIZE, SPRITES_Y_SIZE, 6, false, 1));	//・３
}

void EnemyMushroom::setup() {
	frameCnt++;
	if (frameCnt % 120 == 0) {
		switch (step) {
		case 0:
			if (animationManagerPtr->change(0)) {
				xSpeed = 0;
			}
			step = 1;
			break;
		case 1:
			if (animationManagerPtr->change(1)) {
				turn = true;
				xSpeed = -speed;
			}
			step = 2;
			break;
		case 2:
			if (animationManagerPtr->change(0)) {
				xSpeed = 0;
			}
			step = 3;
			break;
		default:
			if (animationManagerPtr->change(1)) {
				turn = false;
				xSpeed = speed;
			}
			step = 0;
			break;
		}
	}
}