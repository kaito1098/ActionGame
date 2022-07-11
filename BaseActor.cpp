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
	//�E�摜���オ���_�Ȃ̂ŁA�^���I�Ɍ��_�����[�����ƂȂ�悤�������Ă���
	m_animationManagerPtr->draw(m_x - m_xSize / 2, m_y - m_ySize, m_turn);
}

int BaseActor::x() {
	return m_x;
}

int BaseActor::y() {
	return m_y;
}

bool BaseActor::checkFalling() {
	//TODO�F���ۂɂ͂ǂ����肷�ׂ����H
	return m_y < (GROUND_HEIGHT);
}