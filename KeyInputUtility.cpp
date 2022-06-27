#include "KeyInputUtility.h"
#include "DxLib.h"

KeyInputUtility::KeyInputUtility(int _keyCode) :
	keyCode(_keyCode), pressed(false) {
}

//�E������Ă��邩�H�i�`���^�����O�l���Ȃ��j
bool KeyInputUtility::onPressed() {
	return CheckHitKey(keyCode) == 1;
}

//�E������Ă��邩�H�i�`���^�����O�l������j
bool KeyInputUtility::onPressedOnce() {
	if (CheckHitKey(keyCode) == 1 && !pressed) {
		pressed = true;
		return true;
	} else if (CheckHitKey(keyCode) == 0) {
		pressed = false;
	}
	return false;
}