#include "Result.h"
using namespace KamataEngine;

void Result::Initialize()
{
	isRetry = false;
	isTitle = false;
}

void Result::Update()
{
	if (Input::GetInstance()->TriggerKey(DIK_A))//
	{											//
		isRetry = true;							//
	}											// 仮シーン変更
												// 押された瞬間に変わる
	if (Input::GetInstance()->TriggerKey(DIK_D))//
	{											//
		isTitle = true;							//
	}
}


void Result::Draw()
{

}