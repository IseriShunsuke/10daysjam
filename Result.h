#pragma once
#include "KamataEngine.h"

class Result
{
public:

	~Result();
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

	bool GetRetry() { return isRetry; }
	bool GetTitle() { return isTitle; }
private:
	bool isRetry;
	bool isTitle;
};

