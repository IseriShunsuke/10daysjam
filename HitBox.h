#pragma once
#include "KamataEngine.h"
#include <cmath>
bool IsCollision(const KamataEngine::WorldTransform& player, const KamataEngine::WorldTransform& box);

static inline const float kWidth = 64.0f;
static inline const float kHeight = 64.0f;

class HitBox
{

};

