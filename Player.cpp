#include "Player.h"

using namespace KamataEngine;

Player::~Player()
{
	delete sprite_;
}

// 初期化
void Player::Initialize(uint32_t texture)
{
	size = { 64.0f, 64.0f };
	texture_ = texture;

	
	worldTransform_.Initialize();
	// 初期回転
	worldTransform_.translation_ = { 110.0f, 350.0f, 0 };
	worldTransform_.scale_ = {1.0f, 1.0f, 1.0f};

	sprite_ = Sprite::Create(texture_, { worldTransform_.translation_.x, worldTransform_.translation_.y }, { 1, 1, 1, 1 }, { 0.5f, 0.5f });
}

// 更新
void Player::Update()
{
	// 移動入力
	if (Input::GetInstance()->PushKey(DIK_D)) {
		worldTransform_.translation_.x += 3.0f;
	}
	if (Input::GetInstance()->PushKey(DIK_A)) {
		worldTransform_.translation_.x -= 3.0f;
	}
	if (Input::GetInstance()->PushKey(DIK_W)) {
		worldTransform_.translation_.y -= 3.0f;
	}
	if (Input::GetInstance()->PushKey(DIK_S)) {
		worldTransform_.translation_.y += 3.0f;
	}


	worldTransform_.UpdateMatrix();
	sprite_->SetPosition({ worldTransform_.translation_.x, worldTransform_.translation_.y });
}

// 描画
void Player::Draw()
{

	sprite_->Draw();
}



