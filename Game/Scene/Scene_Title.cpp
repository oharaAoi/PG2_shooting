#include "Scene_Title.h"

Scene_Title::Scene_Title(){
	Init();
}

Scene_Title::~Scene_Title(){
	
}

/*=========================================
	初期化関数
==========================================*/
void Scene_Title::Init(){
	GH_ = Novice::LoadTexture("./Resources/images/title.png");
}

/*=========================================
	更新関数
==========================================*/
void Scene_Title::Update(){
	if (MyNovice::IsTriggerKey(DIK_SPACE)) {
		sceneNo_ = SCENE_GAME;
		isSceneTransition_ = true;
	}
}

/*=========================================
	描画関数
==========================================*/
void Scene_Title::Draw(){
	Novice::DrawSprite(0, 0, GH_, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);
}
