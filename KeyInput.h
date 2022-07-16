#pragma once
#include "KeyInputUtility.h"
#include "DxLib.h"
#include <memory>

/** @brief �e��L�[���͂��󂯕t����I�u�W�F�N�g */
namespace KeyInput {
	extern std::unique_ptr<KeyInputUtility> DOWN;
	extern std::unique_ptr<KeyInputUtility> UP;
	extern std::unique_ptr<KeyInputUtility> RIGHT;
	extern std::unique_ptr<KeyInputUtility> LEFT;
	extern std::unique_ptr<KeyInputUtility> Z;
	extern std::unique_ptr<KeyInputUtility> X;
	extern std::unique_ptr<KeyInputUtility> LSHIFT;
}