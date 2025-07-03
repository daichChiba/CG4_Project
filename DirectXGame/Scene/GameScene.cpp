#include "GameScene.h"

using namespace KamataEngine;

GameScene::GameScene() {}

GameScene::~GameScene() {
	Model2::StaticFinalize();

	for (WorldTransform* wt : worldTransform_) {
		delete wt;
	}
	worldTransform_.clear();

	delete model_;
	delete ringModel;

	// カメラの解放
	delete camera_;
	camera_ = nullptr;
}

void GameScene::Initialize() {
	// DirectXCommonインスタンスの取得
	dxCommon_ = DirectXCommon::GetInstance();
	// Inputインスタンスの取得
	input_ = Input::GetInstance();
	// Audioインスタンスの取得
	audio_ = Audio::GetInstance();

	ringWorldTransform.Initialize();

	// カメラの初期化
	camera_ = new Camera();
	camera_->Initialize();
	
	for (int i = 0; i < 5; i++) {
		WorldTransform* wt = new WorldTransform();
		wt->Initialize();
		wt->translation_ = {i * 5.0f, 0.0f, 0.0f};
		worldTransform_.push_back(wt);
	}

	Model2::StaticInitialize();
	model2Handle_ = TextureManager::Load("./Resources/uvChecker.png");
	//model_ = Model2::CreateFromOBJ("Panel", true);
	model_ = Model2::CreateSquare(5);
	ringModel = Model2::CreateRing(4);
}

void GameScene::Update() {
	ringWorldTransform.UpdateMatrix();
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

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model2::PreDraw(commandList);

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>
	//for (WorldTransform* wt : worldTransform_) {
	//	model_->Draw(*wt, *camera_, model2Handle_);
	//}
	ringModel->Draw(ringWorldTransform, *camera_, model2Handle_);

	// 3Dオブジェクト描画後処理
	Model2::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}
