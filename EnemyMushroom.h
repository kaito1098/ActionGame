#pragma once
#include "BaseActor.h"

class EnemyMushroom : public BaseActor {
public:
	EnemyMushroom(int x, int y);
protected:
	void setup() override;
};