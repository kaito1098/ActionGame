#pragma once
#include "Animation.h"
#include <vector>
#include <memory>

class AnimationManager {
public:
	AnimationManager();
	void add(std::shared_ptr<Animation> animPtr);
	bool change(int idx, bool force = false);
	void update();
	void draw(int x, int y, bool turn);
	bool isIdle();
	int getBusyLevel();
private:
	std::vector<std::shared_ptr<Animation>> animations;
	int currentIdx;
};