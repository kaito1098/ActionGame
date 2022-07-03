#pragma once
#include "AnimationManager.h"
#include <vector>
#include <memory>

class BaseActor {
public:
	BaseActor(int x, int y, int speed, int xSize, int ySize);
	void update();
	void draw();
	virtual void hit() = 0;
protected:
	int x, y, speed;	//�E�v���C���[�̕`����W�A�ړ����x
	int xSpeed, ySpeed;	//�EX���������x�AY���������x�A��������X�������ۑ����x
	int xSize, ySize;	//�E�X�v���C�g�摜�̏c���T�C�Y
	bool turn;			//�E���E���]�`��t���O�i�E�����𐳂Ƃ���j
	std::shared_ptr<AnimationManager> animationManagerPtr;
	bool checkFalling();
	virtual void setup() = 0;
};