#include "KamataEngine.h"
#include "Scene/scenes/GameScene.h"
#include "Scene/scenes/TitleScene.h"
#include <Windows.h>
#include <map>

enum class SelectScene {
	Titel,
	Game,
};

Scene* scene = nullptr;

void SceneChange(SelectScene& scene_);

using namespace KamataEngine;
// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
	// エンジンの初期化
	Initialize(L"LE3D_16_チバ_ダイチ");

	// DirectXCommonインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();



	scene = new TitleScene;
	scene->SetUp();

	SelectScene sceneSelect = SelectScene::Titel;

	//メインループ
	while (true) {
		// エンジンの更新
		if (Update()) {
			break;
		}


		// シーンの更新
		scene->Update();

		// 描画開始
		dxCommon->PreDraw();

		// ここに描画処理を記述する

		// シーンの描画
		scene->Draw();



		// 描画終了
		dxCommon->PostDraw();

		if (scene->IsFinish()) {
			SceneChange(sceneSelect);
		}
	}
	// シーンのリソースを削除
	scene->Delete();

	delete scene;
	// ゲームシーンの解放
	scene = nullptr;

	// エンジンの終了処理
	Finalize();



	return 0;
}

void SceneChange(SelectScene& scene_) {
	// シーンを切り替える順番
	std::map<SelectScene, SelectScene> selectScene{
	    {SelectScene::Titel, SelectScene::Game },
	    {SelectScene::Game,  SelectScene::Titel},
	};
	// シーンの切り替え
	scene_ = selectScene[scene_];
	// シーンのリソースを削除
	scene->Delete();
	delete scene;
	// シーンに該当する関数を生成
	std::map<SelectScene, Scene*> sceneNext{
	    {SelectScene::Titel, new TitleScene()},
        {SelectScene::Game, new GameScene()}
    };
	// シーンを生成する
	scene = sceneNext[scene_];
	scene->SetUp();
}