#include "Stage.h"
using namespace KamataEngine;

void Stage::Initialize() {
	skyTexture_ = TextureManager::Load("sky.png");
	for (int i = 0; i < 2; i++) {
		Vector2 StartPos = {640.0f + 1280.0f * i, 360.0f};
		Sprite* sprite = Sprite::Create(skyTexture_, StartPos);
		sprite->SetAnchorPoint(Vector2(0.5f, 0.5f));
		if (i == 1) {
			sprite->SetIsFlipX(true);
			//sprite->SetIsFlipY(true);
		}
		skysprite_.push_back(sprite);
		/*skysprite_[i] = Sprite::Create(skyTexture_, {640.0f * 1280.0f * i, 360.0f});
		skysprite_[i]->SetAnchorPoint(Vector2(0.5f, 0.5f));*/
	}
}

void Stage::Update() {
	for (int i = 0; i < 2; i++) {
		skysprite_[i]->SetPosition({skysprite_[i]->GetPosition().x - spriteSpeed, skysprite_[i]->GetPosition().y});
		if (skysprite_[i]->GetPosition().x<=-640.0f) {
			skysprite_[i]->SetPosition(reStartPos_);
		}
	}
}

void Stage::Draw() {
	for (int i = 0; i < 2; i++) {
		skysprite_[i]->Draw();
	}
}

void Stage::Delete() {
	for (int i = 0; i < 2; i++) {
		delete skysprite_[i];
	}
}
