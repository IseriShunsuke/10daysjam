#include <Windows.h>
#include "kamataEngine.h"
#include "GameScene.h"
#include "TitleScene.h"
using namespace KamataEngine;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
	KamataEngine::Initialize(L"LE3D_03_イセリ_シュンスケ_確認04_04");

	DirectXCommon* dxcommon = DirectXCommon::GetInstance();

	GameScene* gameScene = new GameScene;

	/*TitleScene* titleScene = new TitleScene;*/

	gameScene->Initialize();

	/*titleScene->Initialize();*/

	while (true) {
		if (KamataEngine::Update()) {
			break;
		}

		gameScene->Update();

		/*titleScene->Update();*/

		dxcommon->PreDraw();

	

		/*titleScene->Draw();*/

		gameScene->Draw();


		

		dxcommon->PostDraw();
	}
	// エンジン終了
	KamataEngine::Finalize();
	return 0;
}
