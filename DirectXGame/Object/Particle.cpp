#include "Particle.h"
using namespace KamataEngine;
using namespace MathUtility;
void Particle::Initialize(Model* model) {
#ifdef _DEBUG
	// Nullポインタチェック
	assert(model);
#endif // _DEBUG
	// モデルの設定
	model_ = model;
	// ワールド変換データの初期化
	worldTransform_.Initialize();

	// 色の設定
	objectColor_.Initialize();
	color_ = Vector4(1, 1, 0, 1);
}

void Particle::Update() {

	// 色変更オブジェクトに色の数値を設定する
	objectColor_.SetColor(color_);

	// 移動
	worldTransform_.translation_ += {0.0f, 0.1f, 0.0f};

	// 行列を定数バッファに転送
	worldTransform_.UpdateMatrix();
}

void Particle::Draw(Camera& camera) {
	model_->Draw(worldTransform_, camera,&objectColor_);
}
