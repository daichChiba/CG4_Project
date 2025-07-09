#pragma once
#include "KamataEngine.h"

#include "../Scene.h"

class TitleScene : public Scene{
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
	void Initialize() override;
	/// <summary>
	/// 更新
	/// </summary>
	void Update() override;
	/// <summary>
	/// 描画
	/// </summary>
	void Draw() override;

	/// <summary>
	/// 削除
	/// </summary>
	void Delete() override;

private:
	// カウンター
	int counter_;
	// カウントスピード
	int countSpeed_;
	// 表示させる際の上限
	const int kDrawCount_ = 30;
	// 一秒あたりのフレーム数
	const int kCountFrame_ = 60;
	// タイトルが落ちてくるスピード
	float titelSpeed_;
	const float kTitelSpeed_ = 1.0f;

private:


	//テクスチャ
	uint32_t whitePanelTexture_;
	uint32_t pushButtonTexture_;
	uint32_t gameTitelTexture_;
	//スプライト
	KamataEngine::Sprite* whitePanelSprite_ = nullptr;
	KamataEngine::Sprite* pushButtonSprite_ = nullptr;
	KamataEngine::Sprite* gameTitelSprite_ = nullptr;
};
