#include "TitleScene.h"
using namespace KamataEngine;

TitleScene::~TitleScene()
{ 
	delete sprite_; 
}

void TitleScene::Initialize()
{
	// カメラの初期化
	camera_.Initialize();

	textureHandle_ = TextureManager::Load("stage.png");
	sprite_ = Sprite::Create(textureHandle_, { 640.0f, 360.0f }, { 1, 1, 1, 1 }, { 0.5f, 0.5f });

	isFinish = false;
}

void TitleScene::Update()
{
	if (Input::GetInstance()->TriggerKey(DIK_SPACE))
	{
		isFinish = true;
	}
}

void TitleScene::Draw() 
{
	DirectXCommon* dxcommon = DirectXCommon::GetInstance();


	Sprite::PreDraw(dxcommon->GetCommandList());
	
	sprite_->Draw(); 

	Sprite::PostDraw();
}
