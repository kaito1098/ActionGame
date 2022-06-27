#include "AnimationManager.h"
#include "DxLib.h"

AnimationManager::AnimationManager() :
	currentIdx(0) {
}

//�E�A�j���[�V�����̒ǉ��i��ԍŏ��ɒǉ������A�j���[�V�������f�t�H���g�ƂȂ�j
void AnimationManager::add(std::shared_ptr<Animation> animPtr) {
	animations.emplace_back(animPtr);
}

//�E�Đ�����A�j���[�V������ύX����i���ݍĐ����̃A�j���[�V�����͏����������j
void AnimationManager::change(int idx) {
	if (currentIdx != idx) {
		animations[currentIdx]->reset();
		currentIdx = idx;
	}
}

void AnimationManager::update() {
	if (animations[currentIdx]->update()) {
		//�E�A�j���[�V�������I��������f�t�H���g�A�j���[�V�����ɑJ��
		animations[currentIdx]->reset();
		currentIdx = 0;
	}
}

void AnimationManager::draw(int x, int y, bool turn) {
	if (turn) {
		DrawTurnGraph(x, y, animations[currentIdx]->getGraphHandle(), TRUE);
	} else {
		DrawGraph(x, y, animations[currentIdx]->getGraphHandle(), TRUE);
	}
}