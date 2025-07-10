#pragma once
#include "KamataEngine.h"
#include <vector>
class Stage {
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
	void Draw();
	/// <summary>
	/// 削除
	/// </summary>
	void Delete();

private:
	// テクスチャ
	uint32_t skyTexture_;
	// スプライト
	std::vector<KamataEngine::Sprite*> skysprite_;
	int spriteNum = 2;

	const KamataEngine::Vector2 reStartPos_ = {1920.0f, 360.0f};

	const float spriteSpeed = 1.0f;

	// const KamataEngine::Vector2 startPos_ = {640.0f, 360.0f};
	// const KamataEngine::Vector2 startPos2nd_ = {1920.0f, 360.0f};

private:
};