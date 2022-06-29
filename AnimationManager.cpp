#include "AnimationManager.h"
#include "DxLib.h"

AnimationManager::AnimationManager() :
	currentIdx(0) {
}

//・アニメーションの追加（一番最初に追加したアニメーションがデフォルトとなる）
void AnimationManager::add(std::shared_ptr<Animation> animPtr) {
	animations.emplace_back(animPtr);
}

//・再生するアニメーションを変更する
//・ビジーレベルを考慮し、変更に成功した場合trueを返す
//・forceにtrueが渡されたとき、ビジーレベルを考慮しない（非ループアニメーション⇒アイドル状態への遷移を想定）
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
		//・アニメーションが終了したらデフォルトアニメーションに遷移
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