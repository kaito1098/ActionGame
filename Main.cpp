#include "Common.h"
#include "DxLib.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {
	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(TRUE);
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32);
	SetAlwaysRunFlag(TRUE);
	if (DxLib_Init() == -1) return -1;

	gameManagerPtr->main();

	DxLib_End();
	return 0;
}