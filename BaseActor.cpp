#include "BaseActor.h"
#include "Common.h"

BaseActor::BaseActor(int _x, int _y, int _speed, int _xSize, int _ySize) :
	m_x(_x), m_y(_y), m_baseSpeed(_speed), m_xSize(_xSize), m_ySize(_ySize), m_xSpeed(0), m_ySpeed(0), m_turn(false) {
}

void BaseActor::update() {
	setup();
	m_x += m_xSpeed;
	m_y += m_ySpeed;
	m_animationManagerPtr->update();
}

void BaseActor::draw() {
	//・画像左上が原点なので、疑似的に原点が下端中央となるよう調整している
	m_animationManagerPtr->draw(m_x - m_xSize / 2, m_y - m_ySize, m_turn);
}

int BaseActor::getX() {
	return m_x;
}

int BaseActor::getY() {
	return m_y;
}

bool BaseActor::checkFalling() {
	//TODO：実際にはどう判定すべきか？
	return m_y < (GROUND_HEIGHT);
}