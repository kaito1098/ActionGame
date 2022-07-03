#pragma once
#include "BaseActor.h"

class EnemyMushroom : public BaseActor {
public:
	EnemyMushroom(int x, int y);
	void hit() override;
protected:
	void setup() override;
};