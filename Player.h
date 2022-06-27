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
	int x, y;	//�E�v���C���[�̕`����W
	std::shared_ptr<AnimationManager> animationManagerPtr;
};