#include "KamataEngine.h"

// ゲームシーン
class Items
{
public:

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();


private:

	// アイテム種類
	enum ItemsType
	{
		kItemsTunakan,
		kItemsJetEngine,
		kItemsTorpedo,
	};
	ItemsType itemsType_;

	// スプライト
	KamataEngine::Sprite* itemsSprite_ = nullptr;

	// テクスチャ
	uint32_t itemsTextureHandle_[3];

	// 座標
	KamataEngine::Vector2 itemsPosition_ = {};

	float itemsSpeed_ = 5.0f;

};
