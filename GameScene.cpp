#include "GameScene.h"
#include "Math.h"

using namespace KamataEngine;


// デストラクタ
GameScene::~GameScene()
{
	delete player_;
	delete graphBar;
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
	graphBarHandle_ = TextureManager::Load("white1x1.png");
	textureHandleNumber_ = TextureManager::Load("number.png");

	model_ = Model::CreateFromOBJ("player");

	player_ = new Player();
	player_->Initialize(model_);

	stage_ = new Stage();
	stage_->Initialize(backGraundTextureHandle_);

	graphBar = new GraphBar();
	graphBar->Initialize(graphBarHandle_);
	hp_ = 0;

	drawNumber_ = new DrawNumber();
	drawNumber_->Initialize(textureHandleNumber_);
	gameScore_ = 0;
}

// 更新
void GameScene::Update()
{

	hp_--;
	if (hp_ < 0) {
		hp_ = 200;
	}

	gameScore_++;

	player_->Update();
	stage_->Update();
	graphBar->Update(hp_);
	drawNumber_->Update(gameScore_);
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

	graphBar->Draw();
	drawNumber_->Draw();


	Sprite::PostDraw();
}