#include "player.h"

Player::Player(){
	Init();
}

Player::~Player(){
	SafeDelete(bulletManager_);
}

/*=========================================
	初期化関数
==========================================*/
void Player::Init(){
	bulletManager_ = new BulletManager();

	LoadJson::LoadEntityStatus("./Resources/json/playerDate.json");

	worldPos_ = LoadJson::GetEntityDate().worldPos;
	size_ = LoadJson::GetEntityDate().size;
	theta_ = LoadJson::GetEntityDate().theta;
	scale_ = LoadJson::GetEntityDate().scale;
	leftTop_ = LoadJson::GetEntityDate().leftTop;
	ScreenRectVertex(localVertex_, size_);
	MakeScreenMatrix();

	isAlive_ = true;

	color_ = 0xffffffff;

	GH_ = Novice::LoadTexture("./Resources/images/player.png");

	velocity_ = { 0.0f, 0.0f };
	accelation_ = { 0.0f, 0.0f };
	gravity_ = -0.8f;

	// ------------------------------------------------------------------------
	hp_ = 5;

	// ------------------------------------------------------------------------
	address_ = CalcAddress(worldVertex_, 64.0f);
	preAddress_ = address_;

	// ------------------------------------------------------------------------
	bulletCoolTime_ = 0;
	coolTimeLimit_ = 5;

	chargeTime_ = 0;
	chargeCoolTime_ = 0;

	// ------------------------------------------------------------------------
	isInvincible_ = false;
	isChargeShot_ = false;

	// ------------------------------------------------------------------------
	invincibleCount_ = 0;

	// ------------------------------------------------------------------------
	for (int i = 0; i < 5; i++) {
		lifePos_[i] = { 100.0f + (i * 32), 670 };
	}

	lifeGH_ = Novice::LoadTexture("./Resources/images/life.png");
	 
}

/*=========================================
	更新関数
==========================================*/
void Player::Update(){
	Move();
	Shot();
	ScreenClamp();
	Invincible();

	if (MyNovice::IsTriggerKey(DIK_Q)) {
		LoadJson::LoadEntityStatus("./Resources/json/playerDate.json");
		Init();
	}

	MakeScreenMatrix();

	address_ = CalcAddress(worldVertex_, 64.0f);
	AddressClamp();

	bulletManager_->Update(worldPos_);
}

/*=========================================
	描画関数
==========================================*/
void Player::Draw(){
	DrawQuad(
		screenVertex_,
		size_,
		leftTop_,
		GH_,
		color_
	);

	for (int i = 0; i < hp_; i++) {
		Novice::DrawSprite(
			static_cast<int>(lifePos_[i].x),
			static_cast<int>(lifePos_[i].y),
			lifeGH_,
			1.0f,
			1.0f,
			0.0f,
			0xffffffff
		);
	}

	bulletManager_->Draw();
}

/*=========================================
	移動
==========================================*/
void Player::Move(){
	preAddress_ = CalcAddress(worldVertex_, 64.0f);

	if (MyNovice::IsPressKey(DIK_A)) {
		velocity_.x = -4.0f;
	}

	if (MyNovice::IsPressKey(DIK_D)) {
		velocity_.x = 4.0f;
	} 

	if (MyNovice::IsTriggerKey(DIK_SPACE)) {
		velocity_ = { 2.0f, 30.0f };
		accelation_ = { 0.0f, 20.0f };
		isJump_ = true;
	}

	if (!inBubble_) {
		accelation_.y += gravity_;
		velocity_ += accelation_;

		worldPos_ += velocity_;
	}

	if (!isJump_) {
		accelation_ = { 0.0f, 0.0f };
	}
	velocity_ = { 0.0f, 0.0f };
	
}

/*=========================================
	弾を撃つ
==========================================*/
void Player::Shot(){
	// 単発弾の処理
	if (bulletCoolTime_ == 0) {
		if (MyNovice::IsPressMouse(0)) {
			bulletManager_->BulletCreate(worldPos_, 0);
			bulletCoolTime_++;
		}
	} else {
		bulletCoolTime_++;

		if (bulletCoolTime_ > coolTimeLimit_) {
			bulletCoolTime_ = 0;
		}
	}

	// チャージの処理
	if (MyNovice::IsPressMouse(1)) {
		chargeTime_++;

		if (chargeTime_ > 128) {
			chargeTime_ = 128;
		}
	} else if (chargeTime_ != 0) {
		bulletManager_->BulletCreate(worldPos_, chargeTime_);
		chargeTime_ = 0;
		isChargeShot_ = true;
	}

	if (isChargeShot_) {
		chargeCoolTime_++;

		if (chargeCoolTime_ > 60) {
			isChargeShot_ = false;
			chargeCoolTime_ = 0;
		}
	}
}

/*=========================================
	プレイヤーを画面内に収める
==========================================*/
void Player::ScreenClamp(){
	worldPos_.x = Clampf(worldPos_.x, 0.0f + size_.x / 2.0f, 1280.0f - size_.x / 2.0f);
}

/*=========================================
	アドレスを範囲内に収める
==========================================*/
void Player::AddressClamp(){
	//
	if (address_.lt.row < 0) {
		address_.lt.row = 0;
	}

	if (address_.rt.row < 0) {
		address_.rt.row = 0;
	}

	if (address_.lb.row < 0) {
		address_.lb.row = 0;
	}

	if (address_.rb.row < 0) {
		address_.rb.row = 0;
	}
}

/*=========================================
	無敵時間
==========================================*/
void Player::Invincible(){
	if (isInvincible_) {
		invincibleCount_++;

		if (invincibleCount_ > 100) {
			isInvincible_ = false;
			invincibleCount_ = 0;
		}
	}
}
