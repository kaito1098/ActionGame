#include "Common.h"
#include "DxLib.h"

KeyInputUtility::KeyInputUtility(int _keyCode) :
	keyCode(_keyCode), pressed(false) {
}

//・押されているか？（チャタリング考慮なし）
bool KeyInputUtility::onPressed() {
	return CheckHitKey(keyCode) == 1;
}

//・押されているか？（チャタリング考慮あり）
bool KeyInputUtility::onPressedOnce() {
	if (CheckHitKey(keyCode) == 1 && !pressed) {
		pressed = true;
		return true;
	} else if (CheckHitKey(keyCode) == 0) {
		pressed = false;
	}
	return false;
}