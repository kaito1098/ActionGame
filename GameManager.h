#pragma once
#include "Player.h"
#include "EnemyMushroom.h"
#include <memory>

class GameManager {
public:
	void main();
private:
	void init();
	void update();
	void draw();
	std::unique_ptr<Player> playerPtr;
	//ETODOFEnemy‚ÍManagerŠÇ—‚É‚·‚é
	std::unique_ptr<EnemyMushroom> mushroomPtr;
};