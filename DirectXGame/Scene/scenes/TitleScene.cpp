#include "TitleScene.h"
using namespace KamataEngine;

TitleScene::TitleScene() {

}

TitleScene::~TitleScene() {

}

void TitleScene::Initialize() {

	whitePanelTexture_ = TextureManager::Load("whitePanel.png");
	pushButtonTexture_ = TextureManager::Load("pushButton.png");
	gameTitelTexture_ = TextureManager::Load("gameTitle.png");

	whitePanelSprite_ = Sprite::Create(whitePanelTexture_, {0,0});
	pushButtonSprite_ = Sprite::Create(pushButtonTexture_,{320,400});
	gameTitelSprite_ = Sprite::Create(gameTitelTexture_,{320,200});

}

void TitleScene::Update() {
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

	pushButtonSprite_->Draw();
	gameTitelSprite_->Draw();

	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}

void TitleScene::Delete() {
	delete whitePanelSprite_;
	delete pushButtonSprite_;
	delete gameTitelSprite_;
}