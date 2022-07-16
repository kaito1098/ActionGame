#include "Common.h"

ICollider::ICollider(IColliderHolder* holderPtr, int dx, int dy) :
    m_holderPtr(holderPtr), m_dx(dx), m_dy(dy) {
}