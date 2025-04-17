#include "Particle.h"
using namespace KamataEngine;
using namespace MathUtility;
#include <algorithm>
void Particle::Initialize(KamataEngine::Model* model, KamataEngine::Vector3 pos, KamataEngine::Vector3 velocity) {
#ifdef _DEBUG
	// Nullポインタチェック
	assert(model);
#endif // _DEBUG
	// モデルの設定
	model_ = model;
	// 位置の変更
	worldTransform_.translation_ = pos;
	// 移動量の設定
	velocity_ = velocity;
	// 大きさ
	worldTransform_.scale_ = {0.2f, 0.2f, 0.2f};
	// 色の設定
	objectColor_.Initialize();
	color_ = Vector4(1, 1, 0, 1);
	// ワールド変換データの初期化
	worldTransform_.Initialize();
}

void Particle::Update() {
	// 終了なら何もしない
	if (isFinished_) {
		return;
	}

	// カウンターを１フレーム分の秒数進める
	counter_ += 1.0f / 60.0f;

	// 存続時間の上限に達したら
	if (counter_ >= kDuration) {
		counter_ = kDuration;
		// 終了フラグを立てる
		isFinished_ = true;
	}

	// 色変更オブジェクトに色の数値を設定する
	objectColor_.SetColor(color_);

	// 移動
	worldTransform_.translation_ += velocity_;

	// フェード処理
	color_.w = std::clamp(1.0f - counter_ / kDuration, 0.0f, 1.0f);

	// 行列を定数バッファに転送
	worldTransform_.UpdateMatrix();
}

void Particle::Draw(Camera& camera) {
	model_->Draw(worldTransform_, camera,&objectColor_);
}
