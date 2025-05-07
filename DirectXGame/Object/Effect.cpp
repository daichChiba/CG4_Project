#include "Effect.h"
using namespace KamataEngine;
void Effect::Initialize(KamataEngine::Model* model, KamataEngine::Vector3 size, KamataEngine::Vector3 rotate) {
	//NULLポインタチェック
	assert(model);
	model_ = model;

	worldTransform_.scale_ = size;
	worldTransform_.rotation_ = rotate;


	worldTransform_.Initialize();
}

void Effect::Update() {
	worldTransform_.TransferMatrix();


}

void Effect::Draw(Camera& camera) {
	model_->Draw(worldTransform_, camera);
}
