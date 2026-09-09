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

	bool GetFinish() { return isFinish; }
private:
	
	uint32_t textureHandle_;

	Sprite* sprite_ = nullptr;

	uint32_t tutorialTextureHandle_[5];

	Sprite* spriteTutorial_ = nullptr;

	int tutorialpage;

	 // カメラ
	 Camera camera_;

	 bool isFinish;
	 bool isView;
};
