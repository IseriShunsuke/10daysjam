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

private:
	KamataEngine::Sprite* sprite_[5] = {};
	uint32_t textureHandle_;

	KamataEngine::Vector2 size;
};
