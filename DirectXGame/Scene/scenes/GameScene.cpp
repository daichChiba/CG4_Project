#include "GameScene.h"
using namespace KamataEngine;
GameScene::GameScene() {}

GameScene::~GameScene() {


}

void GameScene::Initialize() {
	camera_ = new Camera();
	camera_->Initialize();
	camera_->farZ = 1000.0f;

	stage_.Initialize();
	player_.Initialize();

}



void GameScene::Update() {
	camera_->UpdateMatrix();
	stage_.Update();
	player_.Update();

	if (Input::GetInstance()->PushKey(DIK_SPACE)) {
		isFinish = true;
	}
}

void GameScene::Draw() {

	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>

	stage_.Draw();

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>

	player_.Draw(*camera_);

	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	stage_.ForegroundDraw();

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}

void GameScene::Delete() {
	delete camera_;
	stage_.Delete();
	player_.Delete();
}
