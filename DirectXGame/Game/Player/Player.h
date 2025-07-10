#pragma once
#include "KamataEngine.h"
class Player {
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();
	/// <summary>
	/// 更新
	/// </summary>
	void Update();
	/// <summary>
	/// 描画
	/// </summary>
	void Draw(KamataEngine::Camera& camera);
	/// <summary>
	/// 削除
	/// </summary>
	void Delete();

private:
	/// <summary>
	/// 移動処理
	/// </summary>
	void Move();

	KamataEngine::Vector3 pos_;
	const float playerSpeed = 0.1f;

private:
	KamataEngine::WorldTransform worldTransform_;
	KamataEngine::Model* model_ = nullptr;

};