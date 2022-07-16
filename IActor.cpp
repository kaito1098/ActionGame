#include "Common.h"

IActor::IActor(int _x, int _y, int _speed, int _xSize, int _ySize) :
	m_x(_x), m_y(_y), m_baseSpeed(_speed), m_xSize(_xSize), m_ySize(_ySize), m_xSpeed(0), m_ySpeed(0), m_turn(false) {
}

void IActor::update() {
	setup();
	m_x += m_xSpeed;
	m_y += m_ySpeed;
	m_animationManagerPtr->update();
	if (collider) collider->draw();
}

void IActor::draw() {
	//・画像左上が原点なので、疑似的に原点が下端中央となるよう調整している
	m_animationManagerPtr->draw(m_x, m_y, m_turn);
}

int IActor::getX() {
	return m_x;
}

int IActor::getY() {
	return m_y;
}

void IActor::setX(int x) {
	m_x = x;
}

void IActor::setY(int y) {
	m_y = y;
}