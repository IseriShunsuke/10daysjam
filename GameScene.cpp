#include "GameScene.h"
#include "HitBox.h"
#include "Math.h"

using namespace KamataEngine;


// デストラクタ
GameScene::~GameScene()
{
	delete player_;
	delete stage_;
	delete drawNumber_;

	delete items_;

	for (int i = 0; i < kEnemyCount; i++)
	{
		delete enemies_[i];
	}
}

// 初期化
void GameScene::Initialize()
{

	// カメラの初期化
	camera_.Initialize();

	backGraundTextureHandle_ = TextureManager::Load("stage.png");
	textureHandleNumber_ = TextureManager::Load("number.png");
	textureHandlePlayer_ = TextureManager::Load("player/player1.png");

	player_ = new Player();
	player_->Initialize(textureHandlePlayer_);

	stage_ = new Stage();
	stage_->Initialize(backGraundTextureHandle_);

	hp_ = 2000;

	drawNumber_ = new DrawNumber();
	drawNumber_->Initialize(textureHandleNumber_);
	gameScore_ = 0;

	isRetry = false;
	isTitle = false;
	isDead = false;

	result_ = new Result();
	result_->Initialize();

	itemsTextureHandle_ =
		TextureManager::Load("Items/Tunakan.png");

	items_ = new Items();
	items_->Initialize();

	// 敵テクスチャ読み込み
	enemyTextureHandle_ = TextureManager::Load("Items/Tunakan.png");

	// 敵生成
	for (int i = 0; i < kEnemyCount; i++)
	{
		enemies_[i] = new Enemy();
		enemies_[i]->Initialize(enemyTextureHandle_);
	}
}

// 更新
void GameScene::Update()
{
	if (!isDead)//生きてたら
	{
		hp_--;

		if (hp_ <= 0)
		{
			isDead = true;//死
		}

		gameScore_++;//スコア

		player_->Update();				//
		stage_->Update();				//再利用
		drawNumber_->Update(gameScore_);//

		items_->Update();

		// 敵更新
		for (int i = 0; i < kEnemyCount; i++)
		{
			Vector2 playerPosition = {
				player_->GetPosition().x,
				player_->GetPosition().y
			};

			enemies_[i]->Update(playerPosition);
		}
	}
	else
	{
		result_->Update();

		isRetry = result_->GetRetry();
		isTitle = result_->GetTitle();
	}

}

// 描画
void GameScene::Draw() 
{
	DirectXCommon* dxcommon = DirectXCommon::GetInstance();

	Sprite::PreDraw(dxcommon->GetCommandList());

	stage_->Draw();

	Sprite::PostDraw();

	Model::PreDraw();

	

	Model::PostDraw();

	Sprite::PreDraw(dxcommon->GetCommandList());

	drawNumber_->Draw();

	player_->Draw();

	if (isDead)//死んだら表示
	{
		result_->Draw();
	}

	items_->Draw();

	// 敵描画
	for (int i = 0; i < kEnemyCount; i++)
	{
		enemies_[i]->Draw();
	}

	Sprite::PostDraw();
}