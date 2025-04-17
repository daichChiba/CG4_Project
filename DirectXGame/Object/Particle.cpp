#include "Particle.h"

void Particle::Initialize(Model* model) {
#ifdef _DEBUG
	// Nullポインタチェック
	assert(model);
#endif // _DEBUG
	// モデルの設定
	model_ = model;
	// ワールド変換データの初期化
	worldTransform_.Initialize();
}

void Particle::Update() {

	// 行列を定数バッファに転送
	worldTransform_.TransferMatrix();
}

void Particle::Draw(Camera& camera) {
	model_->Draw(worldTransform_, camera);
}
