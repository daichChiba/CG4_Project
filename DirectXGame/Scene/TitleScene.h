#pragma once
#include "KamataEngine.h"
class TitleScene {
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	TitleScene();
	/// <summary>
	/// デストラクタ
	/// </summary>
	~TitleScene();
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

private:

private:
	KamataEngine::DirectXCommon* dxCommon_ = nullptr;
	KamataEngine::Input* input_ = nullptr;
	KamataEngine::Audio* audio_ = nullptr;

	//テクスチャ
	uint32_t whitePanelTexture_;
	uint32_t pushButtonTexture_;
	uint32_t gameTitelTexture_;
	//スプライト
	KamataEngine::Sprite* whitePanelSprite_ = nullptr;
	KamataEngine::Sprite* pushButtonSprite_ = nullptr;
	KamataEngine::Sprite* gameTitelSprite_ = nullptr;
};
