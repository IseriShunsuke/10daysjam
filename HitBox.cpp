#include "HitBox.h"
using namespace KamataEngine;

bool IsCollisionBox(const KamataEngine::Vector2& player, const KamataEngine::Vector2& box)
{

	if (player.x + kWidth / 2 > box.x - kWidth / 2 && player.x  - kWidth / 2 < box.x + kWidth / 2)
	{
		if (player.y + kHeight / 2 > box.y - kHeight / 2 && player.y  - kHeight / 2 < box.y + kHeight / 2)
		{
			return true;
		}
	}

	return false;
}