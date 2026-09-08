#include "Enemy.h"
#include <cstdlib>
#include <cmath>

using namespace KamataEngine;

Enemy::~Enemy()
{
	delete sprite_;
}

void Enemy::Initialize(uint32_t textureHandle)
{
	textureHandle_ = textureHandle;

	// 右側のランダムな位置から出現
	position_.x = 1280.0f + float(rand() % 721);
	position_.y = float(rand() % (720 - 64));

	// 最初は左向き
	velocity_ = { -speed_, 0.0f };

	sprite_ = Sprite::Create(textureHandle_, position_);

	if (sprite_)
	{
		sprite_->SetAnchorPoint({ 0.5f, 0.5f });
		sprite_->SetSize(size_);
	}
}

void Enemy::Update(Vector2 playerPosition)
{
	// まだ方向を決めていない場合
	if (!directionDecided_)
	{
		// サメからPlayerまでの距離
		float dx = playerPosition.x - position_.x;
		float dy = playerPosition.y - position_.y;

		float distance = std::sqrt(dx * dx + dy * dy);

		if (distance > 0.0f)
		{
			// Player方向に向かう
			velocity_.x = (dx / distance) * speed_;
			velocity_.y = (dy / distance) * speed_;
		}

		// 一度方向を決めたら、もう追尾しない
		directionDecided_ = true;
	}

	// 移動
	position_.x += velocity_.x;
	position_.y += velocity_.y;

	// 左側または上下に画面外へ出たら再出現
	if (position_.x < -100.0f ||
		position_.y < -100.0f ||
		position_.y > 820.0f)
	{
		// 右側のランダムな位置
		position_.x = 1280.0f + float(rand() % 721);
		position_.y = float(rand() % (720 - 64));

		// 次の出現時にPlayer方向を計算し直す
		directionDecided_ = false;
	}

	// スプライト位置更新
	if (sprite_)
	{
		sprite_->SetPosition(position_);
	}
}

void Enemy::Draw()
{
	if (sprite_)
	{
		sprite_->Draw();
	}
}