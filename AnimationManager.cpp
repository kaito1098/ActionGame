#include "AnimationManager.h"
#include "DxLib.h"

AnimationManager::AnimationManager() :
	currentIdx(0) {
}

//・アニメーションの追加（一番最初に追加したアニメーションがデフォルトとなる）
void AnimationManager::add(std::shared_ptr<Animation> animPtr) {
	animations.emplace_back(animPtr);
}

//・再生するアニメーションを変更する（現在再生中のアニメーションは初期化される）
void AnimationManager::change(int idx) {
	animations[currentIdx]->reset();
	currentIdx = idx;
}

void AnimationManager::update() {
	if (animations[currentIdx]->update()) {
		//・アニメーションが終了したらデフォルトアニメーションに遷移
		animations[currentIdx]->reset();
		currentIdx = 0;
	}
}

void AnimationManager::draw(int x, int y) {
	DrawGraph(x, y, animations[currentIdx]->getGraphHandle(), TRUE);
}