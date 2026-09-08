#pragma once

#include "KamataEngine.h"
#include "Effect.h"
#include "Player.h"
#include "Result.h"
#include "Stage.h"
#include "DrawNumber.h"
#include "Enemy.h"
#include "Bear.h"

#include"Items.h"

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

	void AllCollision();


	bool GetRetry() { return isRetry; }
	bool GetTitle() { return isTitle; }
private:
	KamataEngine::Sprite* spritePlayer_;
	Player* player_;
	Stage* stage_;
	DrawNumber* drawNumber_;

	uint32_t backGraundTextureHandle_;
	uint32_t fontTextureHandle_;
	uint32_t textureHandleNumber_;
	uint32_t textureHandlePlayer_;
	KamataEngine::Sprite* spriteFont_ = nullptr;

	int gameScore_;

	int hp_;

	// カメラ
	Camera camera_;

	bool isRetry;
	bool isTitle;
	bool isDead;

	Result* result_;

	//アイテム↓

	Items* items_ = nullptr;
	uint32_t itemsTextureHandle_;

	bool isHit;

	bool isJetEngineActive_ = false;
	int jetEngineTimer_ = 0;
	static const int kJetEngineTime = 60 * 5;

	//アイテム↑

	// 敵
	static const int kEnemyCount = 2;
	Enemy* enemies_[kEnemyCount] = {};
	uint32_t enemyTextureHandle_;

	// クマ
	static const int kBearCount = 2;
	Bear* bears_[kBearCount] = {};
	uint32_t bearTextureHandle_;

	// 魚雷の敵停止タイマー
	float enemyStopTimer_ = 0.0f;

	// 敵の出現停止中
	bool isEnemyStop_ = false;
};

