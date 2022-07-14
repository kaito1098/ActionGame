#include "BaseCollider.h"

BaseCollider::BaseCollider(IColliderHolder* holderPtr, int dx, int dy) :
    m_holderPtr(holderPtr), m_dx(dx), m_dy(dy) {
}