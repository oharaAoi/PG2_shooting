#include "EnemyDownUI.h"

EnemyDownUI::EnemyDownUI(){
	Init();
}

EnemyDownUI::~EnemyDownUI(){
}

void EnemyDownUI::Init(){
	LoadJson::LoadUiStatus("./Resources/json/EnemyDownUI.json");
	pos_ = LoadJson::GetUIDate().worldPos;
	size_ = LoadJson::GetUIDate().size;
	theta_ = LoadJson::GetUIDate().theta;
	scale_ = LoadJson::GetUIDate().scale;
	leftTop_ = LoadJson::GetUIDate().leftTop;

	GH_ = Novice::LoadTexture("./Resources/images/enemyDownUI.png");

	color_ = 0xffffffff;

	WorldRectVertex(localVertex_, size_);
	MakeWorldMatrix();

	drawSize_ = size_;
}

void EnemyDownUI::Update(){
	drawSize_.x = static_cast<float>(15 - EnemyManager::GetTotalDownCount()) / 15.0f * 1000.0f;
	if (drawSize_.x <= 0) {
		drawSize_.x = 0.0f;
	}
	MakeWorldMatrix();
}

void EnemyDownUI::Draw(){
	DrawBox(screenVertex_.lt, drawSize_, 0xFF7F50ff, kFillModeSolid);

	DrawBox(screenVertex_.lt, size_, 0x000000ff, kFillModeWireFrame);
}
