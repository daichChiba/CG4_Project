#pragma once
#include "KamataEngine.h"
#include "../Object/Particle.h"

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

private://------メンバ関数


private: //------メンバ変数
	KamataEngine::DirectXCommon* dxCommon_ = nullptr;
	KamataEngine::Input* input_ = nullptr;
	KamataEngine::Audio* audio_ = nullptr;

	//パーティクル3Dモデルデータ
	KamataEngine::Model* modelParticle_ = nullptr;
	// カメラの初期化
	KamataEngine::Camera camera_;

	// パーティクル
	std::list<Particle*> particles_;

};
