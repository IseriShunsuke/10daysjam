#pragma once
#include "KamataEngine.h"

class DrawNumber 
{
public:
	~DrawNumber();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(uint32_t textureHandle);

	/// <summary>
	/// 更新
	/// </summary>
	void Update(uint32_t number);

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	KamataEngine::Vector2 SetPosition(KamataEngine::Vector2 positon) { return position_ = positon; };

	KamataEngine::Vector2 SetSize(KamataEngine::Vector2 size_) { return size = size_; };

private:
	KamataEngine::Sprite* sprite_[5] = {};
	uint32_t textureHandle_;

	KamataEngine::Vector2 size;

	KamataEngine::Vector2 position_;
};
