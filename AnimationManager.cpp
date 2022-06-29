#include "AnimationManager.h"
#include "DxLib.h"

AnimationManager::AnimationManager() :
	currentIdx(0) {
}

//�E�A�j���[�V�����̒ǉ��i��ԍŏ��ɒǉ������A�j���[�V�������f�t�H���g�ƂȂ�j
void AnimationManager::add(std::shared_ptr<Animation> animPtr) {
	animations.emplace_back(animPtr);
}

//�E�Đ�����A�j���[�V������ύX����
//�E�r�W�[���x�����l�����A�ύX�ɐ��������ꍇtrue��Ԃ�
//�Eforce��true���n���ꂽ�Ƃ��A�r�W�[���x�����l�����Ȃ��i�񃋁[�v�A�j���[�V�����˃A�C�h����Ԃւ̑J�ڂ�z��j
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
		//�E�A�j���[�V�������I��������f�t�H���g�A�j���[�V�����ɑJ��
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

bool AnimationManager::isIdle() {
	return currentIdx == 0;
}

int AnimationManager::getBusyLevel() {
	return animations[currentIdx]->getBusyLevel();
}