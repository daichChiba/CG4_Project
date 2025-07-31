#include "Player.h"
using namespace KamataEngine;

void Player::Initialize() {
	model_ = new Model();
	model_ = Model::CreateFromOBJ("Player", true);

	worldTransform_.Initialize();
	worldTransform_.translation_ = pos_;
	worldTransform_.rotation_.y = 1.0f;
	worldTransform_.scale_ = {4.0f, 4.0f, 4.0f};
}

void Player::Update() {
	worldTransform_.translation_ = pos_;
	Move();
	worldTransform_.UpdateMatrix();
}

void Player::Draw(Camera& camera) {

	model_->Draw(worldTransform_, camera);
}

void Player::Delete() {
	delete model_;
	model_ = nullptr;
}

void Player::Move() {
	if (Input::GetInstance()->PushKey(DIK_D) || Input::GetInstance()->PushKey(DIK_RIGHT)) {
		pos_.x += playerSpeed;
	} else if (Input::GetInstance()->PushKey(DIK_A) || Input::GetInstance()->PushKey(DIK_LEFT)) {
		pos_.x -= playerSpeed;
	}
	if (Input::GetInstance()->PushKey(DIK_W) || Input::GetInstance()->PushKey(DIK_UP)) {
		pos_.y += playerSpeed;
	} else if (Input::GetInstance()->PushKey(DIK_S) || Input::GetInstance()->PushKey(DIK_DOWN)) {
		pos_.y -= playerSpeed;
	}
}
