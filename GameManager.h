#pragma once
#include "Player.h"
#include <memory>

class GameManager {
public:
	void main();
private:
	void init();
	void update();
	void draw();
	std::unique_ptr<Player> playerPtr;
};