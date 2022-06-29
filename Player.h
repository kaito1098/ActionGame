#pragma once
#include "BaseActor.h"
#include "AnimationManager.h"
#include <vector>
#include <memory>

class Player : public BaseActor {
public:
	Player(int x, int y);
protected:
	void setup() override;
};