#include "Bear.h"
#include <cstdlib>

using namespace KamataEngine;

Bear::~Bear()
{
	delete sprite_;
}

void Bear::Initialize(uint32_t textureHandle)
{
	textureHandle_ = textureHandle;

	// 画面上部の右側から出現
	position_.x = 1280.0f;
	position_.y = 50.0f;

	// 最初は左へ移動
	isFalling_ = false;

	sprite_ = Sprite::Create(textureHandle_, position_);

	if (sprite_)
	{
		sprite_->SetAnchorPoint({ 0.5f, 0.5f });
		sprite_->SetSize(size_);
	}
}

void Bear::Update(Vector2 playerPosition)
{
	// 落下していないとき
	if (!isFalling_)
	{
		// 左へ移動
		position_.x -= speed_;

		// PlayerのX座標と近づいたら落下開始
		if (std::abs(position_.x - playerPosition.x) < 10.0f)
		{
			isFalling_ = true;
		}
	}

	// 落下中
	if (isFalling_)
	{
		position_.y += fallSpeed_;
	}

	// 画面下に消えたら再出現
	if (position_.y > 820.0f)
	{
		// 出現停止中なら再出現しない
		if (isSpawnStopped_)
		{
			isActive_ = false;
		} else
		{
			position_.x = 1280.0f;
			position_.y = 50.0f;

			isFalling_ = false;
		}
	}

	// スプライト位置更新
	if (sprite_)
	{
		sprite_->SetPosition(position_);
	}
}

void Bear::Draw()
{
	if (sprite_)
	{
		sprite_->Draw();
	}
}

void Bear::StopSpawn()
{
	isSpawnStopped_ = true;
}

bool Bear::IsActive() const
{
	return isActive_;
}

bool Bear::IsSpawnStopped() const
{
	return isSpawnStopped_;
}

void Bear::RestartSpawn()
{
	isSpawnStopped_ = false;
	isActive_ = true;

	position_.x = 1280.0f;
	position_.y = 50.0f;

	isFalling_ = false;
}