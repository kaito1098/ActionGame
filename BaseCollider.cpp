#include "BaseCollider.h"

BaseCollider::BaseCollider(std::shared_ptr<IColliderHolder> holderPtr, int dx, int dy) :
    m_holderPtr(holderPtr), m_dx(dx), m_dy(dy) {
}