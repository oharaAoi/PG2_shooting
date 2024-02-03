#include "Block.h"

Block::Block(){
	Init();
}

Block::~Block(){
}

/*=========================================
	初期化関数
==========================================*/
void Block::Init(){
	worldPos_ = { 0.0f, 0.0f };
	screenPos_ = worldPos_;
	scale_ = { 1.0f, 1.0f };
	theta_ = 0;

	size_ = { 64, 64 };
	leftTop_ = { 0,0 };

	ScreenRectVertex(localVertex_, size_);
	screenVertex_ = localVertex_;
	worldVertex_ = localVertex_;

	MakeWorldMatrix();
	screenMatrix_ = worldMatrix_;

	GH_ = Novice::LoadTexture("white1x1.png");

	color_ = 0x000000ff;
}

/*=========================================
	更新処理関数
==========================================*/
void Block::Update(){
	MakeScreenMatrix();
}

/*=========================================
	描画関数
==========================================*/
void Block::Draw(){
	DrawQuad(
		screenVertex_,
		size_,
		leftTop_,
		GH_,
		color_
	);
}
