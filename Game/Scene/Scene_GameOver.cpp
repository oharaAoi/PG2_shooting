#include "Scene_GameOver.h"

Scene_GameOver::Scene_GameOver(){
	Init();
}

Scene_GameOver::~Scene_GameOver(){
}

/*=========================================
	初期化関数
==========================================*/
void Scene_GameOver::Init(){
	GH_ = Novice::LoadTexture("./Resources/images/gameOver.png");
}

/*=========================================
	更新関数
==========================================*/
void Scene_GameOver::Update(){
	if (MyNovice::IsTriggerKey(DIK_SPACE)) {
		sceneNo_ = SCENE_TITLE;
		isSceneTransition_ = true;
	}
}

/*=========================================
	描画関数
==========================================*/
void Scene_GameOver::Draw(){
	Novice::DrawBox(0, 0, 1280, 7820, 0.0f, 0x000000ff, kFillModeSolid);

	Novice::DrawSprite(430, 200, GH_, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);
}
