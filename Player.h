#pragma once
#include "BaseActor.h"
#include "Animation.h"
#include "AnimationManager.h"
#include <vector>
#include <memory>

class Player : public BaseActor {
public:
	Player(int x, int y);
	void update();
	void draw();
private:
	int x, y, speed;			//・プレイヤーの描画座標、移動速度
	int xSpeed, ySpeed;			//・X軸方向速度、Y軸方向速度、落下時のX軸方向保存速度
	bool turn;					//・左右反転描画フラグ（右方向を正とする）
	std::shared_ptr<AnimationManager> animationManagerPtr;
	bool checkFalling();
};