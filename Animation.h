#pragma once
#include <vector>
#include <string>

/** @brief 一つのスプライト画像を管理するアニメーションクラス */
class Animation {
public:
	/**
	 * @brief コンストラクタ
	 */
	Animation(std::string filePath, int allNum, int xNum, int yNum, int xSize, int ySize, int animFrameCnt, bool enabledLoop, int busyLevel = 0);

	/**
	 * @brief 必要に応じてスプライト画像のコマ数を進める
	 * @return true：最後のコマまでアニメーションが完了した、false：それ以外（ループ有効時は常にfalse）
	 */
	bool update();

	/**
	 * @brief アニメーションを再生初期状態にリセットする
	 */
	void reset();

	/**
	 * @brief 現在のスプライト画像の１コマの画像ハンドルを取得する
	 * @return 現在フレームで描画すべき画像ハンドル
	 */
	int getGraphHandle();

	/**
	 * @brief ビジーレベルを取得する
	 * @return 現在のアニメーションのビジーレベル
	 * @details ビジーレベルとは
	 * @details アニメーション（アクション）ごとの優先度を管理するための値。
	 * @details ビジーレベルの高いアニメーション再生中は、よりビジーレベルの低いアニメーションは割り込んで再生できない。
	 * @details （例：ジャンプ中（ビジーレベル１）は、左右に移動しても歩行アニメーション（ビジーレベル０）を再生しない）
	 */
	int getBusyLevel();

private:
	/** @brief スプライト画像のハンドル（分割された画像枚数分の動的配列） */
	std::vector<int> sprites;

	/** @brief sprites[] から現在のコマを指定するためのインデックス */
	int spritesIdx;

	/** @brief スプライト画像の分割総数 */
	int allNum;

	/** @brief スプライト画像の分割数（x軸方向） */
	int xNum;

	/** @brief スプライト画像の分割数（y軸方向） */
	int yNum;

	/** @brief 画像１コマあたりの横幅 */
	int xSize;

	/** @brief 画像１コマあたりの縦幅 */
	int ySize;

	/** @brief アニメーション再生開始から毎フレームインクリメントする値 */
	int frameCnt;

	/** @brief 何フレームごとに次のスプライト画像のコマに進めるかの値 */
	int animFrameCnt;

	/** @brief ループ再生フラグ（falseの場合、アニメーションが完了したら自動的にアイドル状態に戻る想定） */
	bool enabledLoop;

	/** @brief ビジーレベル（詳細は getBusyLevel() を参照） */
	int busyLevel;
};