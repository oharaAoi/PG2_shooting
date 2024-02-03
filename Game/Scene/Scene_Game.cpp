#include "Scene_Game.h"

Scene_Game::Scene_Game(){
	Init();
}

Scene_Game::~Scene_Game(){
	SafeDelete(player_);
	SafeDelete(boss_);
	SafeDelete(ground_);
	SafeDelete(mapChip_);
	SafeDelete(enemyManager_);
	SafeDelete(collisionManager_);

	for (int oi = 0; oi < kUIMax; oi++) {
		SafeDelete(ui_[oi]);
	}
}

/*=========================================
	初期化関数
==========================================*/
void Scene_Game::Init(){

	loadJson_->LoadStageDate("./Resources/json/ground.json");

	mapChip_ = new MapChip();

	player_ = new Player();

	boss_ = new Boss();

	ground_ = new Ground();

	enemyManager_ = new EnemyManager();

	collisionManager_ = new CollisionManager(player_, enemyManager_, boss_, ground_);

	ui_[1] = new EnemyDownUI();
	ui_[0] = new BossUI();

	color_ = 0xffffffff;
	isBlackOut_ = false;
	iswhiteOut_ = false;

	blackOut_.easeT = 0;
	blackOut_.frameCount = 0;
	blackOut_.frameLimit = 100;

	whiteOut_.easeT = 0;
	whiteOut_.frameCount = 0;
	whiteOut_.frameLimit = 100;

	GH_ = Novice::LoadTexture("./Resources/images/game.png");
}

/*=========================================
	更新関数
==========================================*/
void Scene_Game::Update(){
	ground_->Update();

	if (player_->GetHp() <= 0) {
		isBlackOut_ = true;
		BlackOut();
		return;
	}

	if (boss_->GetHp() <= 0) {
		iswhiteOut_ = true;
		WhiteOut();
		return;
	}

	player_->Update();
	enemyManager_->Update();

	if (enemyManager_->GetIsEnemysAllDown()) {
		boss_->ShotTargetUpdate(player_->GetWorldPos());
		boss_->Update();
	}

	collisionManager_->Update();

	for (int oi = 0; oi < kUIMax; oi++) {
		ui_[oi]->Update();
	}
}

/*=========================================
	描画関数
==========================================*/
void Scene_Game::Draw(){

	Novice::DrawSprite(0, 0, GH_, 1.0f, 1.0f, 0.0f, 0xFFFFFFFF);

	ground_->Draw();

	player_->Draw();

	if (enemyManager_->GetIsEnemysAllDown()) {
		boss_->Draw();
	}

	enemyManager_->Draw();

	for (int oi = 0; oi < kUIMax; oi++) {
		ui_[oi]->Draw();
	}

	if (isBlackOut_) {
		Novice::DrawBox(0, 0, 1280, 720, 0.0f, color_, kFillModeSolid);
	}

	if (iswhiteOut_) {
		Novice::DrawBox(0, 0, 1280, 720, 0.0f, color_, kFillModeSolid);
	}
}

void Scene_Game::BlackOut(){
	blackOut_.frameCount++;

	blackOut_.easeT = blackOut_.frameCount / blackOut_.frameLimit;

	color_ = ColorShift(0x00000000, 0x000000ff, blackOut_.easeT);

	if (blackOut_.frameCount == blackOut_.frameLimit) {
		sceneNo_ = SCENE_GAMEOVER;
	}
}

void Scene_Game::WhiteOut(){
	whiteOut_.frameCount++;

	whiteOut_.easeT = whiteOut_.frameCount / whiteOut_.frameLimit;

	color_ = ColorShift(0x00000000, 0xffffffff, whiteOut_.easeT);

	if (whiteOut_.frameCount == whiteOut_.frameLimit) {
		sceneNo_ = SCENE_CLEAR;
	}
}
