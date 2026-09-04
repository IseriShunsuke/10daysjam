#include <Windows.h>
#include "kamataEngine.h"
#include "GameScene.h"
#include "TitleScene.h"
using namespace KamataEngine;

GameScene* gameScene = new GameScene;
TitleScene* titleScene = new TitleScene;

enum class Scene
{
	kUnkown = 0,
	KTITLE,
	KWAITING,
	KGAME,
	KGAMEOVER,
	KGAMECLEAR,
};

Scene scene = Scene::kUnkown;
uint32_t soundDataHandle;
uint32_t voiceHandle;

void ChangeScene() {
	switch (scene) {
	case Scene::KTITLE:

		if (titleScene->GetFinish())
		{
			scene = Scene::KGAME;

			delete titleScene;
			titleScene = nullptr;

			gameScene = new GameScene();
			gameScene->Initialize();
		}

		break;
	case Scene::KGAME:
		if (gameScene->GetRetry())
		{

			delete gameScene;
			gameScene = nullptr;

			gameScene = new GameScene();
			gameScene->Initialize();
		}
		else if (gameScene->GetTitle())
		{
			scene = Scene::KTITLE;

			delete gameScene;
			gameScene = nullptr;

			titleScene = new TitleScene();
			titleScene->Initialize();
		}
		break;
	}
}

void UpdateScene() {
	switch (scene) {
	case Scene::KTITLE:
		titleScene->Update();
		break;
	case Scene::KGAME:
		gameScene->Update();
		break;

	}

}

void DrawScene() {
	switch (scene) {
	case Scene::KTITLE:
		titleScene->Draw();
		break;
	case Scene::KGAME:
		gameScene->Draw();
		break;
	}
}

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
	KamataEngine::Initialize(L"LE3D_03_イセリ_シュンスケ_確認04_04");

	DirectXCommon* dxcommon = DirectXCommon::GetInstance();

	titleScene = new TitleScene;
	titleScene->Initialize();

	scene = Scene::KTITLE;

	/*soundDataHandle = Audio::GetInstance()->LoadWave("darkmatter.wav");

	voiceHandle = Audio::GetInstance()->PlayWave(soundDataHandle, true);*/

	while (true) {
		if (KamataEngine::Update()) {
			break;
		}

		ChangeScene();

		// ゲームシーンの更新
		UpdateScene();


		dxcommon->PreDraw();

	

		// ゲームシーンの描画
		DrawScene();
		

		dxcommon->PostDraw();
	}
	// エンジン終了
	KamataEngine::Finalize();
	return 0;
}
