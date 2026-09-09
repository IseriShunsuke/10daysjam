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

	textureHandle_ = TextureManager::Load("title.png");
	sprite_ = Sprite::Create(textureHandle_, { 640.0f, 360.0f }, { 1, 1, 1, 1 }, { 0.5f, 0.5f });

	tutorialTextureHandle_[2] = TextureManager::Load("tutorial/tutorial3.png");
	tutorialTextureHandle_[1] = TextureManager::Load("tutorial/tutorial2.png");
	tutorialTextureHandle_[0] = TextureManager::Load("tutorial/tutorial1.png");
	spriteTutorial_ = Sprite::Create(tutorialTextureHandle_[0], {640.0f, 360.0f}, {1, 1, 1, 1}, {0.5f, 0.5f});

	tutorialpage = 0;

	isFinish = false;
	isView = false;
}

void TitleScene::Update()
{
	if (Input::GetInstance()->TriggerKey(DIK_SPACE))
	{
		isFinish = true;
	}

	if (!isView)
	{
		if (Input::GetInstance()->TriggerKey(DIK_T))
		{
			isView = true;
		}
	}
	else
	{
		if (Input::GetInstance()->TriggerKey(DIK_T))
		{
			isView = false;
		}
		if (Input::GetInstance()->TriggerKey(DIK_D))
		{
			tutorialpage++;
			if (tutorialpage >= 2)
			{
				tutorialpage = 2;
			}
		}
		if (Input::GetInstance()->TriggerKey(DIK_A))
		{
			tutorialpage--;
			if (tutorialpage <= 0)
			{
				tutorialpage = 0;
			}
		}
		spriteTutorial_->SetTextureHandle(tutorialTextureHandle_[tutorialpage]);
	}
}

void TitleScene::Draw() 
{
	DirectXCommon* dxcommon = DirectXCommon::GetInstance();


	Sprite::PreDraw(dxcommon->GetCommandList());
	
	sprite_->Draw(); 

	if (isView)
	{
		spriteTutorial_->Draw();
	}

	Sprite::PostDraw();
}
