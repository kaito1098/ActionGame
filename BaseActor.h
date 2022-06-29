#pragma once
#include "AnimationManager.h"
#include <vector>
#include <memory>

class BaseActor {
public:
	BaseActor(int x, int y, int speed, int xSize, int ySize);
	void update();
	void draw();
protected:
	int x, y, speed;	//・プレイヤーの描画座標、移動速度
	int xSpeed, ySpeed;	//・X軸方向速度、Y軸方向速度、落下時のX軸方向保存速度
	int xSize, ySize;	//・スプライト画像の縦横サイズ
	bool turn;			//・左右反転描画フラグ（右方向を正とする）
	std::shared_ptr<AnimationManager> animationManagerPtr;
	bool checkFalling();
	virtual void setup() = 0;
};