#include "Result.h"
using namespace KamataEngine;

void Result::Initialize()
{
	isRetry = false;
	isTitle = false;

	viewTimer = 0.0f;

	texture_ = TextureManager::Load("SeeResult.png");
	sprite_ = Sprite::Create(texture_, { 640.0f, 360.0f }, { 1, 1, 1, 1 }, { 0.5f, 0.5f });
}

void Result::Update()
{
	viewTimer += 1.0f / 60.0f;

	if (viewTimer >= 3.0f)
	{

		if (Input::GetInstance()->TriggerKey(DIK_A))//
		{											//
			isRetry = true;							//
		}											// 仮シーン変更
													// 押された瞬間に変わる
		if (Input::GetInstance()->TriggerKey(DIK_D))//
		{											//
			isTitle = true;							//
		}
	}
}


void Result::Draw()
{
	sprite_->Draw();
}