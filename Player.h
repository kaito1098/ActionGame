#pragma once
#include "BaseActor.h"
#include <memory>

class Player : public BaseActor {
public:
	Player(int x, int y);
	~Player();
	void update();
	void draw();
private:
	int x, y;						//�E�v���C���[�̕`����W
	int animId;						//�E���݂̃v���C���[�̏�Ԃɂ�����A�j���[�V�����̎��
	int frameCnt, animFrameCnt;		//�E�C���X�^���X��������Ă���̃t���[�����ƁA�A�j���[�V�����̃t���[����
	int* graphIdle;					//�E�A�C�h����Ԃ̃X�v���C�g�Ǘ��p�n���h��
	int graph;						//�E���݂̃t���[���ɂ����ĕ\�����ׂ��摜�̃n���h��
};