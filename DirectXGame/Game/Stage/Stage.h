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
	/// <summary>
	/// 前景の描画
	/// </summary>
	void ForegroundDraw();

private:
	// テクスチャ
	uint32_t skyTexture_;
	uint32_t whiteTexture_;


	// スプライト
	std::vector<KamataEngine::Sprite*> skysprite_;
	std::vector<KamataEngine::Sprite*> gaugeSprite_;
	// 出す画像の総数
	int spriteNum = 2;
	// 背景のリスタート位置
	const KamataEngine::Vector2 reStartPos_ = {1920.0f, 360.0f};
	// ゲージのサイズ
	const KamataEngine::Vector2 stargGaugeSize_ = {200.0f, 20.0f};
	// ゲージの位置
	const KamataEngine::Vector2 gaugePos = {50.0f, 20.0f};
	// 背景の動くスピード
	const float spriteSpeed = 1.0f;
	// ゲージの動くスピード
	const float gaugeSpeed = 0.5f;

private:
};