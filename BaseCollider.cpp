#include "BaseCollider.h"

template <class T>
BaseCollider<T>::BaseCollider(std::shared_ptr<T> holderPtr, int dx, int dy) :
    m_holderPtr(holderPtr), m_dx(dx), m_dy(dy) {
}