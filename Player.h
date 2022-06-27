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
	int x, y;	//・プレイヤーの描画座標
	bool turn;	//・左右反転描画フラグ（右方向を正とする）
	std::shared_ptr<AnimationManager> animationManagerPtr;
};