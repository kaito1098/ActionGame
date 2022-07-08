#pragma once
#include "Animation.h"
#include <vector>
#include <memory>

/** @brief 複数の Animation クラスを管理するマネージャクラス */
class AnimationManager {
public:
	/**
	 * @brief コンストラクタ
	 */
	AnimationManager();

	/**
	 * @brief アニメーションクラスの登録
	 * @param (animPtr) アニメーションクラスの実体を指すポインタ
	 * @details 一番最初に追加したアニメーションがアイドル状態を表すアニメーションとなる。
	 */
	void add(std::shared_ptr<Animation> animPtr);

	/**
	 * @brief 再生するアニメーションを変更する
	 * @param (idx) 変更したいアニメーションの ID
	 * @param (force) true の場合、ビジーレベルを無視して強制的に変更する（規定値：false）
	 * @return ビジーレベルを考慮し、変更に成功した場合 true を返す
	 */
	bool change(int idx, bool force = false);

	/**
	 * @brief 再生中のアニメーションクラスの update() を呼ぶ
	 */
	void update();

	/**
	 * @brief 概要
	 * @param (x) 描画位置（x軸方向）
	 * @param (y) 描画位置（y軸方向）
	 * @param (turn) 左右反転フラグ（true：反転、false：反転なし）
	 */
	void draw(int x, int y, bool turn);

private:
	/** @brief 管理対象のアニメーションクラスを指すポインタの動的配列 */
	std::vector<std::shared_ptr<Animation>> animations;

	/** @brief 概要 */
	int currentIdx;
};