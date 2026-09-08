#pragma once
#include "KamataEngine.h"
#include <numbers>

class Player
{
public:
	~Player();

	// 初期化
	void Initialize(uint32_t texture);

	// 更新
	void Update();

	// 描画
	void Draw();


private:
	//
	uint32_t texture_;
	KamataEngine::Sprite* sprite_;
	KamataEngine::Vector2 size;
	// ワールド変換データ
	KamataEngine::WorldTransform worldTransform_;
	// テクスチャー
	uint32_t textureHandle_;
};

