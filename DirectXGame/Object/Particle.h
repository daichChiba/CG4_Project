#pragma once
#include <KamataEngine.h>


class Particle {
public:
	/// <summary>
	/// 初期化
	/// </summary>
	/// <param name="model">モデル</param>
	/// <param name="pos">位置</param>
	void Initialize(KamataEngine::Model* model, KamataEngine::Vector3 pos, KamataEngine::Vector3 velocity);
	/// <summary>
	/// 更新
	/// </summary>
	void Update();
	/// <summary>
	/// 描画
	/// </summary>
	void Draw(KamataEngine::Camera& camera);
	// デスフラグのgetter
	bool IsFinished() const { return isFinished_; }

private:
	// ワールド変換データ
	KamataEngine::WorldTransform worldTransform_;
	// モデル
	KamataEngine::Model* model_ = nullptr;
	// 色変更オブジェクト
	KamataEngine::ObjectColor objectColor_;
	// 色の数値
	KamataEngine::Vector4 color_;
	// 移動量
	KamataEngine::Vector3 velocity_;

private:
	// 終了フラグ
	bool isFinished_ = false;
	// 経過時間カウント
	float counter_ = 0.0f;
	// 存続時間(消滅までの時間)<秒>
	const float kDuration = 1.0f;
};
