#include "Bullet.h"

Bullet::Bullet(const Vec2f& pos, const int& count) {
	playerPos_ = pos;
	chargeCount_ = count;
	Init();
}

Bullet::~Bullet() {
}

/*=========================================
	初期化関数
==========================================*/
void Bullet::Init() {
	LoadJson::LoadEntityStatus("./Resources/json/BulletDate.json");
	worldPos_ = playerPos_;
	size_ = LoadJson::GetEntityDate().size;
	theta_ = LoadJson::GetEntityDate().theta;
	scale_ = LoadJson::GetEntityDate().scale;
	leftTop_ = LoadJson::GetEntityDate().leftTop;
	speed_ = LoadJson::GetEntityDate().velocity.x;
	accelation_ = LoadJson::GetEntityDate().accelation;

	isAlive_ = true;

	color_ = 0x7FFFD466;

	GH_ = Novice::LoadTexture("white1x1.png");

	if (chargeCount_ != 0) {
		size_ = { static_cast<float>(chargeCount_ / 2),static_cast<float>(chargeCount_ / 2) };
		speed_ /= static_cast<float>(chargeCount_ / 32);
	}

	if (size_.x == static_cast<float>(chargeCount_ / 2)) {
		type_ = Bullet_Charge;
		hp_ = 3;

		lifeTime_ = 0;
		lifeTimeLimit_ = 360;
	} else {
		type_ = Bullet_Normal;
		hp_ = 1;
	}

	ScreenRectVertex(localVertex_, size_);
	MakeScreenMatrix();

	// -------------------------------------------------------------------------
	Vec2f mousePos = MyNovice::GetMousePosf();

	Vec2f dire = Distance(mousePos, worldPos_);
	Normalize(dire);
	velocity_ = { dire.x * speed_, dire.y * speed_ };

	address_ = CalcAddress(worldVertex_, 64.0f);
	preAddress_ = address_;

}

/*=========================================
	更新処理関数
==========================================*/
void Bullet::Update() {
	isAddressOver_ = false;
	worldPos_ += velocity_;

	LifeTime();

	ScreenOut();

	address_ = CalcAddress(worldVertex_, 64.0f);
	AddressClamp();

	if (hp_ <= 0) {
		isAlive_ = false;
	}

	MakeScreenMatrix();
}

/*=========================================
	描画関数
==========================================*/
void Bullet::Draw() {
	DrawQuad(
		screenVertex_,
		size_,
		leftTop_,
		GH_,
		color_
	);
}

/*=========================================
	アドレスの計算でチップの範囲外に行かないように
==========================================*/
void Bullet::AddressClamp() {
	if (address_.lt.col < 0 || address_.lt.col > 19) {
		isAddressOver_ = true;
	}

	if (address_.rt.col < 0 || address_.rt.col > 19) {
		isAddressOver_ = true;
	}

	if (address_.lb.col < 0 || address_.lb.col > 19) {
		isAddressOver_ = true;
	}

	if (address_.rb.col < 0 || address_.rb.col > 19) {
		isAddressOver_ = true;
	}

	//
	if (address_.lt.row < 0 || address_.lt.row >= 2) {
		isAddressOver_ = true;
	}

	if (address_.rt.row < 0 || address_.rt.row >= 2) {
		isAddressOver_ = true;
	}

	if (address_.lb.row < 0 || address_.lb.row >= 2) {
		isAddressOver_ = true;
	}

	if (address_.rb.row < 0 || address_.rb.row >= 2) {
		isAddressOver_ = true;
	}

}

/*=========================================
	範囲外にでたら
==========================================*/
void Bullet::ScreenOut() {
	if (worldPos_.x < -size_.x || worldPos_.x > 1280.0f) {
		isAlive_ = false;
	}

	if (worldPos_.y > 720) {
		isAlive_ = false;
	}
}

/*=========================================
	地面に当たった時の処理
==========================================*/
void Bullet::GroundCollision() {
	velocity_ = { velocity_.x, -velocity_.y };
	worldPos_.y += velocity_.y * 10.0f;

	if (type_ == Bullet_Charge) {
		worldPos_.y += 30.0f;
	}

	worldMatrix_ = MakeAffineMatrix(scale_, theta_, worldPos_);
	worldVertex_ = MakeVertex(localVertex_, worldMatrix_);
}

/*=========================================
	ライフの処理
==========================================*/
void Bullet::LifeTime(){
	if (type_ == Bullet_Charge) {
		lifeTime_++;

		if (lifeTime_ > lifeTimeLimit_) {
			isAlive_ = false;
		}
	}
}
