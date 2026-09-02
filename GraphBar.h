#pragma once
#include  "KamataEngine.h"


class GraphBar 
{
public:
	~GraphBar();

	void Initialize(uint32_t textureHandle);

	void Update(uint32_t hp);

	void Draw();

private:
	KamataEngine::Sprite* sprite_;
	KamataEngine::Sprite* sprite2_;

	uint32_t textureHandle_;
};
