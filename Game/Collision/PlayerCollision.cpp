#include "PlayerCollision.h"

PlayerCollision::PlayerCollision(Player* player, Boss* boss) {
	Init(player, boss);
}

PlayerCollision::~PlayerCollision() {
}

void PlayerCollision::Init(Player* player, Boss* boss) {
	player_ = player;
	boss_ = boss;
	bulletManager_ = player_->GetBulletManager();
	bossBulletManager_ = boss_->GetBulletManager();

	length_ = 0;
}

void PlayerCollision::Update() {
	BulletCollision();
	BossBulletCollision();
}

/*===========================================================================================
	プレイヤーの弾と当たり判定
============================================================================================*/
void PlayerCollision::BulletCollision() {
	if (player_->isChargeShot()) {
		return;
	}

	auto bulletsList = bulletManager_->GetBulletList();
	for (auto bullets = bulletsList->begin(); bullets != bulletsList->end(); ++bullets) {
		if (bullets->GetBulletType() == kBulletType::Bullet_Charge) {
			length_ = Length(bullets->GetWorldPos(), player_->GetWorldPos());

			if (length_ < (player_->GetSize().x / 2) + (bullets->GetSize().x / 2)) {
				player_->SetWorldPos(bullets->GetWorldPos());
				player_->SetInBuble(true);
			} else {
				player_->SetInBuble(false);
			}
		}
	}

	PlayerInBubble();
}

/*===========================================================================================
	ボスの弾との当たり判定
============================================================================================*/
void PlayerCollision::BossBulletCollision() {
	auto bulletsList = bossBulletManager_->GetBossBulletList();

	if (bulletsList->size() == 0) {
		return;
	}

	for (auto bullets = bulletsList->begin(); bullets != bulletsList->end(); ++bullets) {
		length_ = Length(bullets->GetWorldPos(), player_->GetWorldPos());

		if (length_ < (player_->GetSize().x / 2) + (bullets->GetSize().x / 2)) {
			player_->SetHp(player_->GetHp() - 1);
			bullets->SetIsAlive(false);
		}
	}
}

/*===========================================================================================
	更新関数
============================================================================================*/
void PlayerCollision::PlayerInBubble() {
	int num = 0;
	auto bulletsList = bulletManager_->GetBulletList();
	for (auto bullets = bulletsList->begin(); bullets != bulletsList->end(); ++bullets) {
		if (bullets->GetBulletType() == kBulletType::Bullet_Charge) {
			num++;
		}
	}

	if (num == 0) {
		player_->SetInBuble(false);
	}
}
