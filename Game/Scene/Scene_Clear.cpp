#include "Scene_Clear.h"

Scene_Clear::Scene_Clear(){
	Init();
}

Scene_Clear::~Scene_Clear()
{
}

void Scene_Clear::Init(){
	GH_ = Novice::LoadTexture("./Resources/images/clear.png");
}

void Scene_Clear::Update(){
	if (MyNovice::IsTriggerKey(DIK_SPACE)) {
		sceneNo_ = SCENE_TITLE;
		isSceneTransition_ = true;
	}
}

void Scene_Clear::Draw(){
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0xffffffff, kFillModeSolid);

	Novice::DrawSprite(430, 200, GH_, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);
}
