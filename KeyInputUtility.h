#pragma once

class KeyInputUtility {
public:
	KeyInputUtility(int keyCode);
	bool onPressed();
	bool onPressedOnce();
private:
	int keyCode;
	bool pressed;
};