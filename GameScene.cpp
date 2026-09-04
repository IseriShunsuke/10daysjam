#include "GameScene.h"
#include "Math.h"

using namespace KamataEngine;


// デストラクタ
GameScene::~GameScene()
{
	delete player_;
	delete stage_;
	delete drawNumber_;

	delete model_;
}

// 初期化
void GameScene::Initialize()
{
	// カメラの初期化
	camera_.Initialize();

	backGraundTextureHandle_ = TextureManager::Load("stage.png");
	textureHandleNumber_ = TextureManager::Load("number.png");

	model_ = Model::CreateFromOBJ("player");

	player_ = new Player();
	player_->Initialize(model_);

	stage_ = new Stage();
	stage_->Initialize(backGraundTextureHandle_);

	hp_ = 200;

	drawNumber_ = new DrawNumber();
	drawNumber_->Initialize(textureHandleNumber_);
	gameScore_ = 0;

	isRetry = false;
	isTitle = false;
	isDead = false;

	result_ = new Result();
	result_->Initialize();
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

	player_->Draw(camera_);

	Model::PostDraw();

	Sprite::PreDraw(dxcommon->GetCommandList());

	drawNumber_->Draw();

	if (isDead)//死んだら表示
	{
		result_->Draw();
	}

	Sprite::PostDraw();
}