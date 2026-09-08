#pragma once
#include "KamataEngine.h"

class Bear
{
public:

	~Bear();

	// 初期化
	void Initialize(uint32_t textureHandle);

	// 更新
	void Update(KamataEngine::Vector2 playerPosition);

	// 描画
	void Draw();

	void StopSpawn();

	void RestartSpawn();   // ←ここ

	bool IsActive() const;

	bool IsSpawnStopped() const;

private:

	// スプライト
	KamataEngine::Sprite* sprite_ = nullptr;

	// テクスチャ
	uint32_t textureHandle_;

	// 座標
	KamataEngine::Vector2 position_ = {};

	// 移動速度
	float speed_ = 4.0f;

	// クマの大きさ
	KamataEngine::Vector2 size_ = { 64.0f, 64.0f };

	// 落下速度
	float fallSpeed_ = 12.0f;

	// 落下中か
	bool isFalling_ = false;

	bool isActive_ = true;
	bool isSpawnStopped_ = false;
};