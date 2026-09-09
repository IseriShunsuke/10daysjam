#pragma once
#include "KamataEngine.h"

class Enemy
{
public:

	~Enemy();

	void Initialize(uint32_t textureHandle);

	void Update(KamataEngine::Vector2 playerPosition);

	void Draw();

	// 出現停止を開始
	void StopSpawn();

	void RestartSpawn();   // ←ここ

	// 敵が画面内にいるか
	bool IsActive() const;

	// 出現停止中か
	bool IsSpawnStopped() const;

	KamataEngine::Vector2 GetPosition() { return position_; }

private:

	KamataEngine::Sprite* sprite_ = nullptr;

	uint32_t textureHandle_;

	KamataEngine::Vector2 position_ = {};

	KamataEngine::Vector2 velocity_ = {};

	// 移動速度
	float speed_ = 10.0f;

	KamataEngine::Vector2 size_ = { 64.0f, 64.0f };

	// 一度だけ方向を決める
	bool directionDecided_ = false;

	bool isActive_ = true;
	bool isSpawnStopped_ = false;
};