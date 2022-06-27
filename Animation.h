#pragma once

class Animation {
public:
	Animation(const char* filePath, int allNum, int xNum, int yNum, int xSize, int ySize, int animFrameCnt, bool enabledLoop);
	~Animation();
	bool update();
	void reset();
	int getGraphHandle();
private:
	int* sprites;							//�E�X�v���C�g�摜�̃n���h���i�摜�������̔z��j
	int spritesIdx;							//�E�X�v���C�g�摜���猻�݂̃R�}���w�肷��C���f�b�N�X
	const char* filePath;					//�E�X�v���C�g�摜�̃t�@�C���p�X
	int allNum, xNum, yNum, xSize, ySize;	//�E�X�v���C�g�摜�ǂݍ��ݗp�̏��
	int frameCnt, animFrameCnt;				//�E�t���[���J�E���g�ƁA�A�j���P�R�}������̃t���[����
	bool enabledLoop;						//�E���[�v�Đ����L�����H
};