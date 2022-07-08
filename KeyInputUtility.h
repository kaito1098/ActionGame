#pragma once

/**
 * @brief キー入力に関する機能をまとめたクラス
 * @details 基本的には namespace KeyInput にて定義された実体を利用すること。
 */
class KeyInputUtility {
public:
	/** @brief コンストラクタ */
	KeyInputUtility(int keyCode);

	/**
	 * @brief キーが押されているか？（チャタリング考慮なし）
	 * @return true：押されている、false：押されていない
	 * @details 押されている間、毎フレーム true を返却し続ける
	 */
	bool onPressed();

	/**
	 * @brief キーが押されているか？
	 * @return true：押されている、false：押されていない
	 * @details 押された瞬間のフレームのみ true を返却する（毎フレーム判定している前提）
	 */
	bool onPressedOnce();

private:
	/** @brief 判定するキーコード */
	int keyCode;

	/** @brief 押されているフラグ */
	bool pressed;
};