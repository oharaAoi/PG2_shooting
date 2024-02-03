#include "Enemy.h"

Enemy::Enemy(){
	Init();
}

Enemy::~Enemy(){
}

/*===========================================================================================
	初期化関数
============================================================================================*/
void Enemy::Init(){

	// 読み込むファイルをランダムで決める
	randomFileNum_ = RandomInt(2, 1);

	// 右からくるか左からくるかを判定する(基本は左から来る)
	randomPopSide_ = RandomInt(2, 1);

	LoadFile(randomFileNum_);

	worldPos_ = LoadJson::GetEntityDate().worldPos;
	size_ = LoadJson::GetEntityDate().size;
	theta_ = LoadJson::GetEntityDate().theta;
	scale_ = LoadJson::GetEntityDate().scale;
	leftTop_ = LoadJson::GetEntityDate().leftTop;
	velocity_ = LoadJson::GetEntityDate().velocity;
	accelation_ = LoadJson::GetEntityDate().accelation;

	ScreenRectVertex(localVertex_, size_);
	MakeScreenMatrix();

	isAlive_ = true;

	hp_ = 20;

	color_ = 0xffffffff;

	enemyType_ = (EnemyType)randomFileNum_;

	// ---------------------------------------------------------------
	// 右から来る敵は座標と速度を変更しておく
	if (randomPopSide_ == Side_Right) {
		worldPos_.x += 1400.0f;
		velocity_.x *= -1;
	}

	// ---------------------------------------------------------------
	switch (enemyType_) {
	case Snake:
		SnakeMove();
		if (velocity_.x > 0) {
			localVertex_.lt.x *= -1;
			localVertex_.rt.x *= -1;
			localVertex_.lb.x *= -1;
			localVertex_.rb.x *= -1;
		}
		GH_ = Novice::LoadTexture("./Resources/images/snake.png");
		break;

	case Bard:
		keepFirstPosY_ = worldPos_.y;
		flyTheta_ = 0;
		amplitude_ = 100.0f;
		hp_ = 10;
		GH_ = Novice::LoadTexture("./Resources/images/bard.png");
		break;
	}

	// ---------------------------------------------------------------
	initHp_ = hp_;
	uiLeftTop_ = screenVertex_.lt;
	uiSize_ = { 100, 10 };
	drawUiSize_ = { 100, 10 };
}

/*===========================================================================================
	更新処理関数
============================================================================================*/
void Enemy::Update(){
	Move();

	if (hp_ <= 0) {
		isAlive_ = false;
	}

	MakeScreenMatrix();

	uiLeftTop_ = { screenPos_.x - 50,  screenPos_.y - 60 };
	drawUiSize_.x = static_cast<float>(hp_ ) / static_cast<float>(initHp_)* 100.0f;
}

/*===========================================================================================
	描画関数
============================================================================================*/
void Enemy::Draw(){
	DrawQuad(
		screenVertex_,
		size_,
		leftTop_,
		GH_,
		color_
	);

	DrawBox(uiLeftTop_, drawUiSize_, 0xff0000ff, kFillModeSolid);
	DrawBox(uiLeftTop_, uiSize_, 0x000000ff, kFillModeWireFrame);
}

/*===========================================================================================
	移動関数
============================================================================================*/
void Enemy::Move(){
	switch (enemyType_) {
	case Snake:
		SnakeMove();
		break;

	case Bard:
		BardMove();
		break;
	}
}

/*===========================================================================================
	蛇の移動処理
============================================================================================*/
void Enemy::SnakeMove(){
	worldPos_ += velocity_;
}

/*===========================================================================================
	鳥の移動処理
============================================================================================*/
void Enemy::BardMove(){
	worldPos_.x += velocity_.x;

	flyTheta_ += 1.0f / 120.0f * float(M_PI);

	worldPos_.y = keepFirstPosY_ + amplitude_ * sinf(flyTheta_);
}

/*===========================================================================================
	ファイルを読み込む
============================================================================================*/
void Enemy::LoadFile(int num){
	switch (num){
	case Snake:
		LoadJson::LoadEntityStatus("./Resources/json/snakeDate.json");
		break;

	case Bard:
		LoadJson::LoadEntityStatus("./Resources/json/bardDate.json");
		break;
	}
}
