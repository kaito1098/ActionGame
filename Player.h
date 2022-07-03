#pragma once
#include "BaseActor.h"

class Player : public BaseActor {
public:
	Player(int x, int y);
	void hit() override;
protected:
	void setup() override;
};