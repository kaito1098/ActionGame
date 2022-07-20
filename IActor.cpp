#include "Common.h"

IActor::IActor(int _x, int _y, int _speed, int _xSize, int _ySize) :
	m_x(_x), m_y(_y), m_baseSpeed(_speed), m_xSize(_xSize), m_ySize(_ySize), m_xSpeed(0), m_ySpeed(0), m_turn(false), m_falling(false) {
}

void IActor::update() {
	setup();
	m_x += m_xSpeed;
	m_y += m_ySpeed;
	m_animationManagerPtr->update();
}

void IActor::draw(int screenX, int screenY) {
	m_animationManagerPtr->draw(m_x - screenX, m_y - screenY, m_turn);
	if (collider) collider->draw(screenX, screenY);
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

void IActor::fall(int animId) {
    if (collider->checkPassableUnder(m_x, m_y)) {
        //E—Ž‰º
        if (!m_falling) {
            m_falling = true;
            m_xSpeed = 0;
            m_animationManagerPtr->change(animId);
        }
        if (m_ySpeed < MAX_FALL_SPEED) m_ySpeed += GRAVITY;
    } else {
        if (m_falling) {
            //E’…’n
            m_falling = false;
            m_y = collider->getFloorY(m_x, m_y);
            m_xSpeed = 0;
            m_ySpeed = 0;
        }
    }
}