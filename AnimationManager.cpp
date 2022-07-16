#include "Common.h"
#include "DxLib.h"

AnimationManager::AnimationManager() :
	currentIdx(0) {
}

void AnimationManager::add(std::shared_ptr<Animation> animPtr) {
	animations.emplace_back(animPtr);
}

bool AnimationManager::change(int idx, bool force) {
	if (currentIdx != idx) {
		if (force || animations[currentIdx]->getBusyLevel() <= animations[idx]->getBusyLevel()) {
			//�E���ݍĐ����̃A�j���[�V�����͏��������Ď��̃A�j���[�V�����ɑJ��
			animations[currentIdx]->reset();
			currentIdx = idx;
			return true;
		}
		return false;
	}
	return true;
}

void AnimationManager::update() {
	if (animations[currentIdx]->update()) {
		//�E�A�j���[�V�������I�������� ID = 0 �̃A�j���[�V�����ɑJ��
		change(0, true);
	}
}

void AnimationManager::draw(int x, int y, bool turn) {
	if (turn) {
		DrawTurnGraph(x, y, animations[currentIdx]->getGraphHandle(), TRUE);
	} else {
		DrawGraph(x, y, animations[currentIdx]->getGraphHandle(), TRUE);
	}
}