#pragma once
/**
 * すべての実装ファイル（cpp）から参照される想定の宣言ファイル。
 * 実体化可能なクラスの宣言をすべて持つ。
 * （インターフェースは実装クラスが内部構造を知る必要があるため、個別に参照する）
 */

#include "Const.h"

#include "GameManager.h"
#include "AnimationManager.h"

#include "Player.h"
#include "EnemyMushroom.h"

#include "Animation.h"

#include "RectCollider.h"

#include "Map.h"

#include "KeyInputUtility.h"
#include "KeyInput.h"