#pragma once

#include "KamataEngine.h"
#include "Effect.h"
#include "Player.h"
#include "GraphBar.h"
#include "Stage.h"
#include "DrawNumber.h"

// ゲームシーン
class GameScene
{
public:
	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

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
	KamataEngine::Model* model_ = nullptr;
	Player* player_;
	GraphBar* graphBar;
	Stage* stage_;
	DrawNumber* drawNumber_;

	uint32_t graphBarHandle_;
	uint32_t backGraundTextureHandle_;
	uint32_t fontTextureHandle_;
	uint32_t textureHandleNumber_;
	KamataEngine::Sprite* spriteFont_ = nullptr;

	int gameScore_;

	int hp_;

	// カメラ
	Camera camera_;
};

