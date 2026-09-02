#pragma once
#include  "KamataEngine.h"

class Stage 
{
public:
	~Stage();

	void Initialize(uint32_t textureHandle);

	void Update();

	void Draw();

private:
	KamataEngine::Sprite* sprite_;
	KamataEngine::Sprite* sprite2_;

	uint32_t textureHandle_;

};
