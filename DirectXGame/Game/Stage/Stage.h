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
	uint32_t numberTexture_;

	// スプライト
	std::vector<KamataEngine::Sprite*> skysprite_;
	std::vector<KamataEngine::Sprite*> gaugeSprite_;
	std::vector<KamataEngine::Sprite*> numberSprite_;
	// 出す画像の総数
	int spriteNum = 2;
	int numberNum = 5;
	// 背景のリスタート位置
	const KamataEngine::Vector2 reStartPos_ = {1920.0f, 360.0f};
	// ゲージのサイズ
	const KamataEngine::Vector2 stargGaugeSize_ = {200.0f, 20.0f};
	// ゲージの位置
	const KamataEngine::Vector2 gaugePos = {50.0f, 20.0f};
	//数字のサイズ
	const KamataEngine::Vector2 numberSize = {32.0f, 64.0f};
	//数字の位置
	const KamataEngine::Vector2 numberPos = {300.0f, 20.0f};
	// 背景の動くスピード
	const float spriteSpeed = 1.0f;
	// ゲージの動くスピード
	const float gaugeSpeed = 0.5f;
	// カウントの値
	int number;
	// カウントの初期値
	const int kNumber = 0;
	// カウントのスピード
	const int numberSpeed = 1;

	int count;

private:
};