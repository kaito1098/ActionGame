#include "Common.h"

namespace KeyInput {
    std::unique_ptr<KeyInputUtility> DOWN = std::make_unique<KeyInputUtility>(KEY_INPUT_DOWN);
    std::unique_ptr<KeyInputUtility> UP = std::make_unique<KeyInputUtility>(KEY_INPUT_UP);
    std::unique_ptr<KeyInputUtility> RIGHT = std::make_unique<KeyInputUtility>(KEY_INPUT_RIGHT);
    std::unique_ptr<KeyInputUtility> LEFT = std::make_unique<KeyInputUtility>(KEY_INPUT_LEFT);
    std::unique_ptr<KeyInputUtility> Z = std::make_unique<KeyInputUtility>(KEY_INPUT_Z);
    std::unique_ptr<KeyInputUtility> X = std::make_unique<KeyInputUtility>(KEY_INPUT_X);
    std::unique_ptr<KeyInputUtility> LSHIFT = std::make_unique<KeyInputUtility>(KEY_INPUT_LSHIFT);
}