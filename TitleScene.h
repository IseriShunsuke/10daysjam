#pragma once
#include "KamataEngine.h"
#include "Player.h"

using namespace KamataEngine;

class TitleScene 
{
public:
	/// <summary>
	/// デストラクタ
	/// </summary>
	~TitleScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

private:
	
	uint32_t textureHandle_;
	uint32_t textureHandleNext_;

	uint32_t fontTextureHandle_;

	Sprite* sprite_ = nullptr;
	Sprite* spriteNext_ = nullptr;
	Sprite* spriteFont_ = nullptr;

	 KamataEngine::Vector2 position;
	 KamataEngine::Vector2 nextPosition;

	 // カメラ
	 Camera camera_;
};
