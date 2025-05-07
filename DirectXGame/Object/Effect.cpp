#include "Effect.h"
using namespace KamataEngine;
void Effect::Initialize(KamataEngine::Model* model/*, KamataEngine::Vector3 size, KamataEngine::Vector3 rotate*/) {
	// NULLポインタチェック
	assert(model);
	model_ = model;

	worldTransform_.Initialize();

	//worldTransform_.scale_ = size;
	//worldTransform_.rotation_ = rotate;
}

void Effect::Update() { worldTransform_.UpdateMatrix(); }

void Effect::Draw(Camera& camera) { model_->Draw(worldTransform_, camera); }
