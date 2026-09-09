#include "GameScene.h"
#include "HitBox.h"
#include "Math.h"

using namespace KamataEngine;


// デストラクタ
GameScene::~GameScene()
{
	delete player_;
	delete stage_;
	delete drawNumber_;

	delete items_;

	for (int i = 0; i < kEnemyCount; i++)
	{
		delete enemies_[i];
	}

	for (int i = 0; i < kBearCount; i++)
	{
		delete bears_[i];
	}
}

// 初期化
void GameScene::Initialize()
{

	// カメラの初期化
	camera_.Initialize();

	backGraundTextureHandle_ = TextureManager::Load("stage.png");
	textureHandleNumber_ = TextureManager::Load("number.png");
	textureHandlePlayer_ = TextureManager::Load("player/player1.png");
	// クマ
	bearTextureHandle_ = TextureManager::Load("kuma.png");

	player_ = new Player();
	player_->Initialize(textureHandlePlayer_);

	stage_ = new Stage();
	stage_->Initialize(backGraundTextureHandle_);

	hp_ = 2000;

	drawNumber_ = new DrawNumber();
	drawNumber_->Initialize(textureHandleNumber_);
	gameScore_ = 0;

	isRetry = false;
	isTitle = false;
	isDead = false;

	result_ = new Result();
	result_->Initialize();

	itemsTextureHandle_ =
		TextureManager::Load("Items/Tunakan.png");

	items_ = new Items();
	items_->Initialize();


	isHit = false;

	// 敵テクスチャ読み込み
	enemyTextureHandle_ = TextureManager::Load("same.png");

	// 敵生成
	for (int i = 0; i < kEnemyCount; i++)
	{
		enemies_[i] = new Enemy();
		enemies_[i]->Initialize(enemyTextureHandle_);
	}

	for (int i = 0; i < kBearCount; i++)
	{
		bears_[i] = new Bear();
		bears_[i]->Initialize(bearTextureHandle_);
	}

	enemyStopTimer_ = 0.0f;
	isEnemyStop_ = false;

	for (int i = 0; i < 6; i++)
	{
		isHitEnemy_[i] = {};
	}

	isMutekiTimer = false;
	mutekiTimer = 3.0f;

	seDataHandle = Audio::GetInstance()->LoadWave("SE.wav");
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

		if (isMutekiTimer)
		{
			mutekiTimer -= 1.0f / 60.0f;

			if (mutekiTimer <= 0.0f)
			{
				mutekiTimer = 3.0f;
				isMutekiTimer = false;
			}
		}

		gameScore_++;//スコア

		player_->Update();				//
		stage_->Update();				//再利用
		drawNumber_->Update(gameScore_);//

		items_->Update();
		AllCollision();

		// 敵更新
		for (int i = 0; i < kEnemyCount; i++)
		{
			Vector2 playerPosition = {
				player_->GetPosition().x,
				player_->GetPosition().y
			};

			enemies_[i]->Update(playerPosition);
		}

		// クマ
		Vector2 playerPosition = {
	    player_->GetPosition().x,
	    player_->GetPosition().y
		};

		if (isEnemyStop_)
		{
			enemyStopTimer_ -= 1.0f / 60.0f;

			if (enemyStopTimer_ <= 0.0f)
			{
				enemyStopTimer_ = 0.0f;
				isEnemyStop_ = false;

				// サメを再出現可能にする
				for (int i = 0; i < kEnemyCount; i++)
				{
					enemies_[i]->RestartSpawn();
				}

				// クマを再出現可能にする
				for (int i = 0; i < kBearCount; i++)
				{
					bears_[i]->RestartSpawn();
				}
			}
		}

		for (int i = 0; i < kBearCount; i++)
		{
			bears_[i]->Update(playerPosition);
		}

		if (isJetEngineActive_)
		{
			jetEngineTimer_--;

			if (jetEngineTimer_ <= 0)
			{
				isJetEngineActive_ = false;

				player_->SetPlayerSpeed(
					player_->GetPlayerSpeed() - 2.0f);
			}
		}

	} else
	{
		result_->Update();

		isRetry = result_->GetRetry();
		isTitle = result_->GetTitle();
	}

	
}

void GameScene::AllCollision()
{
	//if (!items_->GetIsActive())
	//{
	//	return;
	//}

	isHit = IsCollisionBox(player_->GetPosition(), items_->GetPosition());

	// サメ
	for (int i = 0; i < kEnemyCount; i++)
	{
		isHitEnemy_[i] = IsCollisionBox(player_->GetPosition(), enemies_[i]->GetPosition());
	}
	// クマ
	for (int i = 0; i < kBearCount; i++)
	{
		isHitEnemy_[i + 3] = IsCollisionBox(player_->GetPosition(), bears_[i]->GetPosition());
	}
	if (isHitEnemy_[0] || isHitEnemy_[1] || isHitEnemy_[2])
	{
		if (!isMutekiTimer)
		{
			hp_ -= 10;

			isMutekiTimer = true;

			// サメに当たったときだけ音
			Audio::GetInstance()->PlayWave(seDataHandle, false, 0.1f);
		}

		if (isHitEnemy_[0])
		{
			isHitEnemy_[0] = false;
		}
		if (isHitEnemy_[1])
		{
			isHitEnemy_[1] = false;
		}
		if (isHitEnemy_[2])
		{
			isHitEnemy_[2] = false;
		}
	}

	if (isHitEnemy_[3] || isHitEnemy_[4] || isHitEnemy_[5])
	{
		if (!isMutekiTimer)
		{
			hp_ -= 10;

			isMutekiTimer = true;

			// クマに当たったときも音
			Audio::GetInstance()->PlayWave(seDataHandle, false, 0.1f);
		}

		if (isHitEnemy_[3])
		{
			isHitEnemy_[3] = false;
		}
		if (isHitEnemy_[4])
		{
			isHitEnemy_[4] = false;
		}
		if (isHitEnemy_[5])
		{
			isHitEnemy_[5] = false;
		}
	}

	if (isHit)
	{

		switch (items_->GetItemsType())
		{
		case Items::kItemsTunakan:
			hp_ += 200;
			break;

		case Items::kItemsJetEngine:

			if (!isJetEngineActive_)
			{
				isJetEngineActive_ = true;
				jetEngineTimer_ = kJetEngineTime;

				player_->SetPlayerSpeed(
					player_->GetPlayerSpeed() + 2.0f);
			}
			break;

		case Items::kItemsTorpedo:
			
			isEnemyStop_ = true;
			enemyStopTimer_ = 2.5f;

			// サメ
			for (int i = 0; i < kEnemyCount; i++)
			{
				enemies_[i]->StopSpawn();
			}

			// クマ
			for (int i = 0; i < kBearCount; i++)
			{
				bears_[i]->StopSpawn();
			}

			break;
		}
		items_->ReItemsRespawn();
	}

	if (isHitEnemy_[0] || isHitEnemy_[1] || isHitEnemy_[2])
	{
		if (!isMutekiTimer)
		{
			hp_ -= 10;

			isMutekiTimer = true;
		}

		if (isHitEnemy_[0] )
		{
			isHitEnemy_[0] = false;
		}
		if (isHitEnemy_[1])
		{
			isHitEnemy_[1] = false;
		}
		if (isHitEnemy_[2])
		{
			isHitEnemy_[2] = false;
		}

	}

	if (isHitEnemy_[3] || isHitEnemy_[4] || isHitEnemy_[5])
	{
		if (!isMutekiTimer)
		{
			hp_ -= 10;

			isMutekiTimer = true;
		}

		if (isHitEnemy_[3])
		{
			isHitEnemy_[3] = false;
		}
		if (isHitEnemy_[4])
		{
			isHitEnemy_[4] = false;
		}
		if (isHitEnemy_[5])
		{
			isHitEnemy_[5] = false;
		}

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



	Model::PostDraw();

	Sprite::PreDraw(dxcommon->GetCommandList());

	drawNumber_->Draw();


	if (hp_ / 250 >= 7.0f)
	{
		textureHandlePlayer_ = TextureManager::Load("player/player1.png");
		player_->SetTexture(textureHandlePlayer_);
	}
	if (hp_ / 250 < 7.0f && hp_ / 250 >= 6.0f )
	{
		textureHandlePlayer_ = TextureManager::Load("player/player2.png");
		player_->SetTexture(textureHandlePlayer_);
	}
	if (hp_ / 250 < 6.0f && hp_ / 250 >= 5.0f)
	{
		textureHandlePlayer_ = TextureManager::Load("player/player3.png");
		player_->SetTexture(textureHandlePlayer_);
	}
	if (hp_ / 250 < 5.0f && hp_ / 250 >= 4.0f)
	{
		textureHandlePlayer_ = TextureManager::Load("player/player4.png");
		player_->SetTexture(textureHandlePlayer_);
	}
	if (hp_ / 250 < 4.0f && hp_ / 250 >= 3.0f)
	{
		textureHandlePlayer_ = TextureManager::Load("player/player5.png");
		player_->SetTexture(textureHandlePlayer_);
	}
	if (hp_ / 250 < 3.0f && hp_ / 250 >= 2.0f)
	{
		textureHandlePlayer_ = TextureManager::Load("player/player6.png");
		player_->SetTexture(textureHandlePlayer_);
	}
	if (hp_ / 250 < 2.0f && hp_  >= 0.1f)
	{
		textureHandlePlayer_ = TextureManager::Load("player/player7.png");
		player_->SetTexture(textureHandlePlayer_);
	}
	if (hp_ == 0.0f)
	{
		textureHandlePlayer_ = TextureManager::Load("player/player8.png");
		player_->SetTexture(textureHandlePlayer_);
	}

	player_->Draw();

	// 敵描画
	for (int i = 0; i < kEnemyCount; i++)
	{
		enemies_[i]->Draw();
	}

	// クマ
	for (int i = 0; i < kBearCount; i++)
	{
		bears_[i]->Draw();
	}

	items_->Draw();

	if (isDead)//死んだら表示
	{
		result_->Draw();
		drawNumber_->SetPosition({ 350.0f,300.0f });
		drawNumber_->SetSize({ 32.0f * 4, 64.0f * 4 });
		drawNumber_->Draw();
	}

	

	

	Sprite::PostDraw();
}