#include "EnemyCollision.h"

EnemyCollision::EnemyCollision(Player* player, EnemyManager* enemyManger){
	Init(player, enemyManger);
}

EnemyCollision::~EnemyCollision(){
}

void EnemyCollision::Init(Player* player, EnemyManager* enemyManger){
	player_ = player;
	enemyManager_ = enemyManger;
	bulletManager_ = player_->GetBulletManager();

	length_ = 0;
}

void EnemyCollision::Update(){
	PlayerCollision();
	BulletCollision();
}

/*===========================================================================================
	bulletと
============================================================================================*/
void EnemyCollision::BulletCollision(){
	auto bulletsList = bulletManager_->GetBulletList();
	auto enemyList = enemyManager_->GetEnemyList();
	for (auto enemys = enemyList->begin(); enemys != enemyList->end(); ++enemys) {
		for (auto bullets = bulletsList->begin(); bullets != bulletsList->end(); ++bullets) {
			length_ = Length(enemys->GetWorldPos(), bullets->GetWorldPos());

			if (length_ < (enemys->GetSize().x / 2.0f) + (bullets->GetSize().x / 2.0f)) {
				enemys->SetHp(enemys->GetHp() - 1);

				if (bullets->GetBulletType() == kBulletType::Bullet_Normal) {
					bullets->SetIsAlive(false);
				} else {
					bullets->SetHp(bullets->GetHp() - 1);
				}
			}
		}
	}
}

/*===========================================================================================
	playerと
============================================================================================*/
void EnemyCollision::PlayerCollision(){
	// 無敵だったら判定をとらない
	if (player_->GetIsInvincible()) {
		return;
	}

	auto enemyList = enemyManager_->GetEnemyList();
	for (auto enemys = enemyList->begin(); enemys != enemyList->end(); ++enemys) {
		length_ = Length(enemys->GetWorldPos(), player_->GetWorldPos());

		if (length_ < (enemys->GetSize().x / 2.0f) + (player_->GetSize().x / 2.0f)) {
			player_->SetHp(player_->GetHp() - 1);
			player_->SetIsInvincible(true);
		}
	}
}
