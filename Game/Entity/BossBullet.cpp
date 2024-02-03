#include "BossBullet.h"

BossBullet::BossBullet(const Vec2f& bossPos, const Vec2f& playerPos){
	bossPos_ = bossPos;
	playerPos_ = playerPos;
	Init();
}

BossBullet::~BossBullet(){
}

void BossBullet::Init(){
	LoadJson::LoadEntityStatus("./Resources/json/BossBulletDate.json");
	worldPos_ = bossPos_;
	size_ = LoadJson::GetEntityDate().size;
	theta_ = LoadJson::GetEntityDate().theta;
	scale_ = LoadJson::GetEntityDate().scale;
	leftTop_ = LoadJson::GetEntityDate().leftTop;
	speed_ = LoadJson::GetEntityDate().velocity.x;
	accelation_ = LoadJson::GetEntityDate().accelation;

	isAlive_ = true;

	color_ = 0x7FFFD4ff;

	GH_ = Novice::LoadTexture("white1x1.png");

	ScreenRectVertex(localVertex_, size_);
	MakeScreenMatrix();

	Vec2f distance = Distance(playerPos_, bossPos_);
	Normalize(distance);

	velocity_ = { distance.x * speed_, distance.y * speed_ };

}

void BossBullet::Update(){
	worldPos_ += velocity_;
	MakeScreenMatrix();
}

void BossBullet::Draw(){
	DrawQuad(
		screenVertex_,
		size_,
		leftTop_,
		GH_,
		color_
	);
}
