#include "TitleScene.h"
using namespace KamataEngine;

TitleScene::TitleScene() {}

TitleScene::~TitleScene() {}

void TitleScene::Initialize() {

	counter_ = 0;
	countSpeed_ = 1;
	titelSpeed_ = 0;




	whitePanelTexture_ = TextureManager::Load("whitePanel.png");
	pushButtonTexture_ = TextureManager::Load("pushButton.png");
	gameTitleTexture_ = TextureManager::Load("gameTitle.png");

	whitePanelSprite_ = Sprite::Create(whitePanelTexture_, whitePanelStartPos);
	whitePanelSprite_->SetAnchorPoint(Vector2(0.5f, 0.5f));
	gameTitleSprite_ = Sprite::Create(gameTitleTexture_, titleStartPos);
	gameTitleSprite_->SetAnchorPoint(Vector2(0.5f, 0.5f));
	pushButtonSprite_ = Sprite::Create(pushButtonTexture_, pushButtonStartPos);
	pushButtonSprite_->SetAnchorPoint(Vector2(0.5f, 0.5f));
}

void TitleScene::Update() {
	counter_ += countSpeed_;

	if (gameTitleSprite_->GetPosition().y<titleGoalPos.y) {
		titelSpeed_ += kTitelSpeed_;
		gameTitleSprite_->SetPosition(Vector2(titleGoalPos.x, gameTitleSprite_->GetPosition().y + titelSpeed_));
	}

	if (Input::GetInstance()->TriggerKey(DIK_RETURN)) {
		isFinish = true;
	}
}

void TitleScene::Draw() {

	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>

	whitePanelSprite_->Draw();

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>

	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>

	if (counter_ % kCountFrame_ >= kDrawCount_) {
		pushButtonSprite_->Draw();
	}
	gameTitleSprite_->Draw();

	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}

void TitleScene::Delete() {

	delete whitePanelSprite_;
	delete pushButtonSprite_;
	delete gameTitleSprite_;
}