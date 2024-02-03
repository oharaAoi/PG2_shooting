#include "Boss.h"

int Boss::hp_ = 300;

Boss::Boss(){
	Init();
}

Boss::~Boss(){
	SafeDelete(bulletManager_);
}

/*===========================================================================================
	初期化関数
============================================================================================*/
void Boss::Init(){
	bulletManager_ = new BossBulletManager();

	LoadJson::LoadEntityStatus("./Resources/json/BossDate.json");

	worldPos_ = LoadJson::GetEntityDate().worldPos;
	size_ = LoadJson::GetEntityDate().size;
	theta_ = LoadJson::GetEntityDate().theta;
	scale_ = LoadJson::GetEntityDate().scale;
	leftTop_ = LoadJson::GetEntityDate().leftTop;
	ScreenRectVertex(localVertex_, size_);
	MakeScreenMatrix();

	isAlive_ = true;

	GH_ = Novice::LoadTexture("./Resources/images/boss.png");

	color_ = 0xFFFFFFFF;

	// -------------------------------------------------------------------------------------
	initPos_ = worldPos_;

	isAppearance_ = true;

	appearance_.easeT = 0;
	appearance_.frameCount = 0;
	appearance_.frameLimit = 120;

	// count ------------------------------------
	shotCount_ = 0;
	shotCountLimit_ = 3;

	// time ------------------------------------
	bulletCoolTime_ = 0;
	bulletCoolTimeLimit_ = 40;

	bulletShotCoolTime_ = 0;
	bulletShotCoolTimeLimit = 240;

}

/*===========================================================================================
	更新関数
============================================================================================*/
void Boss::Update(){
	Appearance();

	if (!isAppearance_) {
		Shot();
	}

	bulletManager_->Update();

	MakeScreenMatrix();
}

/*===========================================================================================
	描画関数
============================================================================================*/
void Boss::Draw(){
	DrawQuad(
		screenVertex_,
		size_,
		leftTop_,
		GH_,
		color_
	);

	bulletManager_->Draw();
}

/*===========================================================================================
	登場する
============================================================================================*/
void Boss::Appearance(){
	if (isAppearance_) {
		appearance_.frameCount++;

		appearance_.easeT = appearance_.frameCount / appearance_.frameLimit;

		worldPos_ = Lerp(initPos_, { 1000, initPos_.y }, appearance_.easeT);

		if (appearance_.frameCount > appearance_.frameLimit) {
			isAppearance_ = false;
		}
	}
}

/*===========================================================================================
	弾を撃つ
============================================================================================*/
void Boss::Shot(){
	if (bulletShotCoolTime_ == 0) {
		if (bulletCoolTime_ == 0) {
			bulletManager_->BossBulletCreate(worldPos_);
			bulletCoolTime_++;
		} else {
			bulletCoolTime_++;

			// 弾を撃つ感覚の判定
			if (bulletCoolTime_ >= bulletCoolTimeLimit_) {
				bulletCoolTime_ = 0;
				shotCount_++;
			}

			// 弾を撃った回数の判定
			if (shotCount_ >= shotCountLimit_) {
				shotCount_ = 0;
				bulletShotCoolTime_++;
			}
		}

	} else {
		bulletShotCoolTime_++;

		if (bulletShotCoolTime_ > bulletShotCoolTimeLimit) {
			bulletShotCoolTime_ = 0;
		}
	}

}

/*===========================================================================================
	マネジャーのプレイヤーの座標を変える
============================================================================================*/
void Boss::ShotTargetUpdate(const Vec2f& playerPos){
	bulletManager_->PlayerPosUpdate(playerPos);
}
