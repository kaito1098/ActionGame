#include "RectCollider.h"

bool RectCollider::isCollide(std::shared_ptr<RectCollider> target) {
    //E‹éŒ`“¯Žm‚ÌÕ“Ë”»’è
    if (target->top >= bottom && target->bottom <= top &&
        target->left >= right && target->right <= left) {
        return true;
    }
    return false;
}

void RectCollider::pushCollidersTree() {
    //EŠ‘®‚·‚é‹óŠÔ‚ðŒvŽZ‚µ‚ÄŽl•ª–Ø‚ÉŽ©g‚ð“o˜^‚·‚é

}