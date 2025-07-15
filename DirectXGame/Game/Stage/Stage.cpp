#include "Stage.h"
using namespace KamataEngine;

void Stage::Initialize() {
	skyTexture_ = TextureManager::Load("sky.png");
	whiteTexture_ = TextureManager::Load("white1x1.png");
	numberTexture_ = TextureManager::Load("number.png");
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

	for (int i = 0; i < numberNum; i++) {
		Vector2 StartPos = {numberPos.x + numberSize.x * i, numberPos.y};
		Sprite* sprite = Sprite::Create(numberTexture_, StartPos);
		sprite->SetSize(numberSize);

		numberSprite_.push_back(sprite);
	}

	number = kNumber;
	count = kNumber;
}

void Stage::Update() {
	number += numberSpeed;
	count = number;
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
	// 最初に割る数値は5桁なので1000で初期設定する
	int32_t digit = 10000;
	for (int i = 0; i < numberNum; i++) {
		// 今の桁の数値を取り出す
		int nowNumber = count / digit;
		// 今の桁の数値の部分を切り出すようにする
		numberSprite_[i]->SetTextureRect({numberSize.x * nowNumber, 0}, numberSize);
		// 次の桁の処理のために、残りの桁の数値にする
		count %= digit;
		// 次の桁の処理のために、割る数値を10で割って桁に応じた値にする。
		digit /= 10;
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
	for (int i = 0; i < numberNum; i++) {
		delete numberSprite_[i];
	}
}

void Stage::ForegroundDraw() {
	for (int i = 0; i < spriteNum; i++) {
		gaugeSprite_[i]->Draw();
	}
	for (int i = 0; i < numberNum; i++) {
		numberSprite_[i]->Draw();
	}
}
