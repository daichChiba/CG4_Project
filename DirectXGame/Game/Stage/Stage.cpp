#include "Stage.h"
using namespace KamataEngine;

void Stage::Initialize() {
	skyTexture_ = TextureManager::Load("sky.png");
	whiteTexture_ = TextureManager::Load("white1x1.png");
	// 背景スプライト
	for (int i = 0; i < spriteNum; i++) {
		Vector2 StartPos = {640.0f + 1280.0f * i, 360.0f};
		Sprite* sprite = Sprite::Create(skyTexture_, StartPos);
		sprite->SetAnchorPoint(Vector2(0.5f, 0.5f));
		if (i == 1) {
			sprite->SetIsFlipX(true);
			//sprite->SetIsFlipY(true);
		}
		skysprite_.push_back(sprite);
	}
	// ゲージスプライト
	for (int i = 0; i < spriteNum; i++) {
		Sprite* sprite = Sprite::Create(whiteTexture_, gaugePos);
		sprite->SetSize(stargGaugeSize_);
		if (i==1) {
			sprite->SetColor(Vector4(0.24f, 0.70f, 0.44f, 0.5f));
		} else {
			sprite->SetColor(Vector4(0.85f, 0.2f, 0.24f, 0.5f));
		}
		gaugeSprite_.push_back(sprite);
	}
}

void Stage::Update() {
	for (int i = 0; i < spriteNum; i++) {
		//背景
		skysprite_[i]->SetPosition({skysprite_[i]->GetPosition().x - spriteSpeed, skysprite_[i]->GetPosition().y});
		if (skysprite_[i]->GetPosition().x<=-640.0f) {
			skysprite_[i]->SetPosition(reStartPos_);
		}

		// ゲージ
		if (i==1) {
			gaugeSprite_[i]->SetSize(Vector2(gaugeSprite_[i]->GetSize().x - gaugeSpeed, stargGaugeSize_.y));
			if (gaugeSprite_[i]->GetSize().x<=0) {
				gaugeSprite_[i]->SetSize(stargGaugeSize_);
			}
		}
	}
}

void Stage::Draw() {
	for (int i = 0; i < spriteNum; i++) {
		skysprite_[i]->Draw();
	}
}

void Stage::Delete() {
	for (int i = 0; i < spriteNum; i++) {
		delete skysprite_[i];
		delete gaugeSprite_[i];
	}

}

void Stage::ForegroundDraw() {
	for (int i = 0; i < spriteNum; i++) {
		gaugeSprite_[i]->Draw();
	}
}
