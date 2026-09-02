#include "TitleScene.h"

TitleScene::~TitleScene()
{ 
	delete sprite_; 
	delete spriteNext_;
}

void TitleScene::Initialize()
{
	// カメラの初期化
	camera_.Initialize();

	textureHandle_ = TextureManager::Load("stage.png");
	textureHandleNext_ = TextureManager::Load("stageB.png");

	position = {0.0f, 0.0f};
	sprite_ = Sprite::Create(textureHandle_, position);

	nextPosition = {1280.0f, 0.0f};
	spriteNext_ = Sprite::Create(textureHandle_, nextPosition);
}

void TitleScene::Update()
{

	position.x -= 2.0f; 
	nextPosition.x -= 2.0f;

	if (position.x <= -1280.0f)
	{
		position.x = 1280.0f;
	}

	if (nextPosition.x <= -1280.0f) {
		nextPosition.x = 1280.0f;
	}

	sprite_->SetPosition(position);
	spriteNext_->SetPosition(nextPosition);
}

void TitleScene::Draw() 
{
	DirectXCommon* dxcommon = DirectXCommon::GetInstance();


	Sprite::PreDraw(dxcommon->GetCommandList());
	
	sprite_->Draw(); 
	spriteNext_->Draw();

	Sprite::PostDraw();
}
