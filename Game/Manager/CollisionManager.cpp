#include "CollisionManager.h"

CollisionManager::CollisionManager(Player* player, EnemyManager* enemyManager, Boss* boss, Ground* ground){
	Init(player,enemyManager,boss, ground);
}

CollisionManager::~CollisionManager(){
}

void CollisionManager::Init(Player* player, EnemyManager* enemyManager, Boss* boss, Ground* ground){

	player_ = player;
	boss_ = boss;
	ground_ = ground;

	enemyManager_ = enemyManager;

	groundCollision_ = new GroundCollision(player_, ground_);
	enemyCollision_ = new EnemyCollision(player_, enemyManager_);
	playerCollision_ = new PlayerCollision(player_, boss_);
	bossCollision_ = new BossCollision(player_, boss_);
}

void CollisionManager::Update(){
	groundCollision_->Update();
	enemyCollision_->Update();
	playerCollision_->Update();
	bossCollision_->Update();
}
