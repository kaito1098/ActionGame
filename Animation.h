#pragma once

class Animation {
public:
	Animation(const char* filePath, int allNum, int xNum, int yNum, int xSize, int ySize, int animFrameCnt, bool enabledLoop, bool busy = false);
	~Animation();
	bool update();
	void reset();
	int getGraphHandle();
	bool isBusy();
private:
	int* sprites;							//�E�X�v���C�g�摜�̃n���h���i�摜�������̔z��j
	int spritesIdx;							//�E�X�v���C�g�摜���猻�݂̃R�}���w�肷��C���f�b�N�X
	const char* filePath;					//�E�X�v���C�g�摜�̃t�@�C���p�X
	int allNum, xNum, yNum, xSize, ySize;	//�E�X�v���C�g�摜�ǂݍ��ݗp�̏��
	int frameCnt, animFrameCnt;				//�E�t���[���J�E���g�ƁA�A�j���P�R�}������̃t���[����
	bool enabledLoop;						//�E���[�v�Đ����L�����H
	bool enabledBusy;						//�E�A�j���[�V�����I���܂Ńr�W�[��Ԃɂ��邩�H�i�K��l�Ffalse�j
	bool busy;								//�E���݂̃r�W�[���
};