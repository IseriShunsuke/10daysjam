#include "KamataEngine.h"

// ゲームシーン
class Items
{
public:

	// アイテム種類
	enum ItemsType
	{
		kItemsTunakan,
		kItemsJetEngine,
		kItemsTorpedo,
	};

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

	KamataEngine::Vector2 GetPosition() { return itemsPosition_; }
	bool GetIsActive() const { return isItemsActive_; }
	void SetIsActive(bool itemsActive) { isItemsActive_ = itemsActive; }
	// アイテム種類取得
	ItemsType GetItemsType()
	{
		return itemsType_;
	}
	void ReItemsRespawn()
	{
		ItemsRespawn();
	}
private:
	ItemsType itemsType_;

	// スプライト
	KamataEngine::Sprite* itemsSprite_ = nullptr;

	// テクスチャ
	uint32_t itemsTextureHandle_[3];

	// 座標
	KamataEngine::Vector2 itemsPosition_ = {};

	float itemsSpeed_ = 5.0f;
	bool isItemsActive_ = true;
	void ItemsRespawn();
};
