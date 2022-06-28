#pragma once

class Animation {
public:
	Animation(const char* filePath, int allNum, int xNum, int yNum, int xSize, int ySize, int animFrameCnt, bool enabledLoop, bool busy = false);
	~Animation();
	bool update();
	void reset();
	int getGraphHandle();
	bool isBusy();
private:
	int* sprites;							//・スプライト画像のハンドル（画像枚数分の配列）
	int spritesIdx;							//・スプライト画像から現在のコマを指定するインデックス
	const char* filePath;					//・スプライト画像のファイルパス
	int allNum, xNum, yNum, xSize, ySize;	//・スプライト画像読み込み用の情報
	int frameCnt, animFrameCnt;				//・フレームカウントと、アニメ１コマあたりのフレーム数
	bool enabledLoop;						//・ループ再生が有効か？
	bool enabledBusy;						//・アニメーション終了までビジー状態にするか？（規定値：false）
	bool busy;								//・現在のビジー状態
};