#include "Common.h"

ICollider::ICollider(IColliderHolder* holderPtr, ColliderID id, int dx, int dy) :
    m_holderPtr(holderPtr), colliderID(id), m_dx(dx), m_dy(dy) {
}