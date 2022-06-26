#pragma once
#include "BaseActor.h"
#include <memory>

class Player : public BaseActor {
public:
	Player(int x, int y);
	~Player();
	void update();
	void draw();
private:
	int x, y;						//・プレイヤーの描画座標
	int animId;						//・現在のプレイヤーの状態におけるアニメーションの種類
	int frameCnt, animFrameCnt;		//・インスタンス生成されてからのフレーム数と、アニメーションのフレーム数
	int* graphIdle;					//・アイドル状態のスプライト管理用ハンドル
	int graph;						//・現在のフレームにおいて表示すべき画像のハンドル
};