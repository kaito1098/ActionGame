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
			//・現在再生中のアニメーションは初期化して次のアニメーションに遷移
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
		//・アニメーションが終了したら ID = 0 のアニメーションに遷移
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