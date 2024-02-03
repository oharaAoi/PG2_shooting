#include "BossUI.h"

BossUI::BossUI(){
	Init();
}

BossUI::~BossUI()
{
}

void BossUI::Init(){
	LoadJson::LoadUiStatus("./Resources/json/EnemyDownUI.json");
	pos_ = LoadJson::GetUIDate().worldPos;
	size_ = LoadJson::GetUIDate().size;
	theta_ = LoadJson::GetUIDate().theta;
	scale_ = LoadJson::GetUIDate().scale;
	leftTop_ = LoadJson::GetUIDate().leftTop;

	GH_ = Novice::LoadTexture("./Resources/images/enemyDownUI.png");

	color_ = 0xff000fff;

	WorldRectVertex(localVertex_, size_);
	MakeWorldMatrix();

	drawSize_ = size_;
}

void BossUI::Update(){
	drawSize_.x = static_cast<float>(Boss::GetHp()) / 300.0f * 1000.0f;
	MakeWorldMatrix();
}

void BossUI::Draw(){
	DrawBox(screenVertex_.lt, drawSize_, color_, kFillModeSolid);

	DrawBox(screenVertex_.lt, size_, 0x000000ff, kFillModeWireFrame);
}
