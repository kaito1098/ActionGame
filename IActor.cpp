#include "Common.h"

IActor::IActor(int _x, int _y, int _speed, int _xSize, int _ySize) :
	m_x(_x), m_y(_y), m_baseSpeed(_speed), m_xSize(_xSize), m_ySize(_ySize), m_xSpeed(0), m_ySpeed(0), m_turn(false) {
}

void IActor::update() {
	setup();
	m_x += m_xSpeed;
	m_y += m_ySpeed;
	m_animationManagerPtr->update();
	if (collider) {
		setPositionByArray(collider->checkMapCollide());
		collider->draw();
	}
}

void IActor::draw() {
	//�E�摜���オ���_�Ȃ̂ŁA�^���I�Ɍ��_�����[�����ƂȂ�悤�������Ă���
	m_animationManagerPtr->draw(m_x, m_y, m_turn);
}

int IActor::getX() {
	return m_x;
}

int IActor::getY() {
	return m_y;
}

void IActor::setPositionByArray(std::array<int, 2> pos) {
	m_x = pos[0];
	m_y = pos[1];
}