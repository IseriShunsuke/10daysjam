#include "HitBox.h"
using namespace KamataEngine;

bool IsCollision(const KamataEngine::WorldTransform& player, const KamataEngine::WorldTransform& box)
{

	if (player.translation_.x + kWidth > box.translation_.x && player.translation_.x  < box.translation_.x + kWidth)
	{
		if (player.translation_.y + kWidth > box.translation_.y && player.translation_.y < box.translation_.y + kWidth)
		{
			return true;
		}
	}

	return false;
}