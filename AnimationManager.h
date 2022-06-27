#pragma once
#include "Animation.h"
#include <vector>
#include <memory>

class AnimationManager {
public:
	AnimationManager();
	void add(std::shared_ptr<Animation> animPtr);
	void change(int idx);
	void update();
	void draw(int x, int y, bool turn);
private:
	std::vector<std::shared_ptr<Animation>> animations;
	int currentIdx;
};