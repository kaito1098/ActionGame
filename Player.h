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
	int x, y, speed;			//�E�v���C���[�̕`����W�A�ړ����x
	int xSpeed, ySpeed;			//�EX���������x�AY���������x�A��������X�������ۑ����x
	bool turn;					//�E���E���]�`��t���O�i�E�����𐳂Ƃ���j
	std::shared_ptr<AnimationManager> animationManagerPtr;
	bool checkFalling();
};