#pragma once
#include "KamataEngine.h"

using namespace KamataEngine;
// ゲームシーン
class GameScene {
public:
	// コンストラクタ
	GameScene();
	// デストラクタ
	~GameScene();
	// 初期化
	void Initialize();
	// 更新
	void Update();
	// 描画
	void Draw();

private:


private:
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	//パーティクル3Dモデルデータ
	Model* modelParticle_ = nullptr;
	// カメラの初期化
	Camera* camera_;
};
