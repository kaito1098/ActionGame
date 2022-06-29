#pragma once
#include "BaseActor.h"

class Player : public BaseActor {
public:
	Player(int x, int y);
protected:
	void setup() override;
};