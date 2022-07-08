#include "RectCollider.h"

bool RectCollider::isCollide(std::shared_ptr<RectCollider> target) {
    //�E��`���m�̏Փ˔���
    if (target->top >= bottom && target->bottom <= top &&
        target->left >= right && target->right <= left) {
        return true;
    }
    return false;
}

void RectCollider::pushCollidersTree() {
    //�E���������Ԃ��v�Z���Ďl���؂Ɏ��g��o�^����

}