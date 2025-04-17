#include "GameScene.h"

#include <random>
using namespace KamataEngine;
using namespace MathUtility;

std::random_device seedGenerator;
std::mt19937 RandomEngine(seedGenerator());
std::uniform_real_distribution<float> RandomFloat(-1.0f, 1.0f);
std::uniform_real_distribution<float> distribution(0.5f, 1.0f);

GameScene::GameScene() {}

GameScene::~GameScene() {

	// パーティクル3Dモデルデータの解放
	delete modelParticle_;
	modelParticle_ = nullptr;

	// パーティクルの解放
	for (Particle* particle : particles_) {
		delete particle;
	}
	particles_.clear();
}

void GameScene::Initialize() {
	// DirectXCommonインスタンスの取得
	dxCommon_ = DirectXCommon::GetInstance();
	// Inputインスタンスの取得
	input_ = Input::GetInstance();
	// Audioインスタンスの取得
	audio_ = Audio::GetInstance();

	// モデルの初期化
	modelParticle_ = Model::CreateSphere(4, 4);

	// カメラの初期化
	camera_.Initialize();

	for (int i = 0; i < 150; i++) {
		// 生成
		Particle* particle = new Particle();
		// 位置
		Vector3 pos = {0.0f, 0.0f, 0.0f};
		// 移動量
		Vector3 velocity = {RandomFloat(RandomEngine), RandomFloat(RandomEngine), 0};
		Normalize(velocity);
		velocity *= distribution(RandomEngine);
		// パーティクルの初期化
		particle->Initialize(modelParticle_, pos,velocity);
		// リストに追加
		particles_.push_back(particle);
	}
}

void GameScene::Update() {
	// パーティクルの更新
	for (Particle* particle : particles_) {
		particle->Update();
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

	// パーティクルの描画
	for (Particle* particle : particles_) {
		particle->Draw(camera_);
	}

	// 3Dオブジェクト描画後処理
	Model::PostDraw();
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
