#include "GameScene.h"

GameScene::GameScene() {}

GameScene::~GameScene() {}

void GameScene::Initialize() {
	// DirectXCommonインスタンスの取得
	dxCommon = DirectXCommon::GetInstance();
	// Inputインスタンスの取得
	input = Input::GetInstance();
	// Audioインスタンスの取得
	audio = Audio::GetInstance();
}

void GameScene::Update() {

}

void GameScene::Draw() {

}

