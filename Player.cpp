#include "Player.h"
#include "DxLib.h"

const int ANIM_FRAME = 6;	//�E�A�j���[�V�����P�R�}�̃t���[����
const int ANIM_ID_IDLE = 0;
const TCHAR* GRAPH_PATH_IDLE = "Data/Actor/Hero/Idle.png";
const int FRAME_COUNT_IDLE = 11;

Player::Player(int _x, int _y) :
	x(_x), y(_y), frameCnt(0), animFrameCnt(0)
{
	//�E�X�v���C�g�n���h���i�[�p�̃������m��
	graphIdle = new int[FRAME_COUNT_IDLE];
	//�E�摜�t�@�C���̃��[�h
	LoadDivGraph(GRAPH_PATH_IDLE, FRAME_COUNT_IDLE, 11, 1, 140, 140, graphIdle);
	graph = graphIdle[0];
	animId = ANIM_ID_IDLE;
}

Player::~Player() {
	//�X�v���C�g�n���h���i�[�p���������
	delete[] graphIdle;
}

void Player::update() {
	frameCnt++;
	//TODO�F�A�j���[�V�����O�ɃL�[���͂ɂ��animID�X�V�H�ł���Ί֐���������
	switch (animId) {
	case ANIM_ID_IDLE:
		if (frameCnt % ANIM_FRAME == 0) {
			animFrameCnt = (animFrameCnt + 1) % FRAME_COUNT_IDLE;
			graph = graphIdle[animFrameCnt];
		}
		break;
	default:
		break;
	}
}

void Player::draw() {
	DrawGraph(x - 70, y - 70, graph, TRUE);
}