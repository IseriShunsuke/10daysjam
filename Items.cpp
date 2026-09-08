#include "Items.h"
#include <cstdlib>
#include <ctime>

using namespace KamataEngine;

void Items::Initialize()
{
	itemsTextureHandle_[0] = TextureManager::Load("Items/Tunakan.png");
	itemsTextureHandle_[1] = TextureManager::Load("Items/JetEngine.png");
	itemsTextureHandle_[2] = TextureManager::Load("Items/Torpedo.png");

	// 乱数初期化
	srand((unsigned int)time(nullptr));

	// ランダムな種類
	itemsType_ = (ItemsType)(rand() % 3);


	// 画面中央
	itemsPosition_.x = 1280.0f;
	itemsPosition_.y = float(rand() % (720 - 64));


	// スプライト生成
	itemsSprite_ = Sprite::Create(itemsTextureHandle_[itemsType_], itemsPosition_);

	// 中央基準にする
	if (itemsSprite_)
	{
		itemsSprite_->SetAnchorPoint({ 0.5f, 0.5f });
	}

	ItemsRespawn();
}

void Items::Update()
{
	
	if (!isItemsActive_)
	{
		return;
	}

	itemsPosition_.x -= itemsSpeed_;

	if (itemsPosition_.x < -100.0f)
	{
		ItemsRespawn();
	}

	if (itemsSprite_)
	{
		itemsSprite_->SetPosition(itemsPosition_);
	}

}

void Items::Draw()
{
	if (!isItemsActive_)
	{
		return;
	}

	if (itemsSprite_)
	{
		itemsSprite_->Draw();
	}

}

void Items::ItemsRespawn()
{
	// 再出現有効
	isItemsActive_ = true;

	// 右端から出現
	itemsPosition_.x = 1280.0f;

	// Y座標ランダム
	itemsPosition_.y = float(rand() % (720 - 64));

	// アイテム種類ランダム
	itemsType_ = (ItemsType)(rand() % 3);

	// 画像切り替え
	delete itemsSprite_;

	itemsSprite_ = Sprite::Create(
		itemsTextureHandle_[itemsType_],
		itemsPosition_);

	if (itemsSprite_)
	{
		itemsSprite_->SetAnchorPoint({ 0.5f, 0.5f });
	}
}
