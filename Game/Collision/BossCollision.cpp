#include "BossCollision.h"

BossCollision::BossCollision(Player* player, Boss* boss) {
	Init(player, boss);
}

BossCollision::~BossCollision() {}


void BossCollision::Init(Player* player, Boss* boss) {
	player_ = player;
	boss_ = boss;
	bulletManager_ = player_->GetBulletManager();

	length_ = 0;

}

void BossCollision::Update() {
	if (!boss_->GetIsAppearance()) {
		BullletCollision();
	}
}

void BossCollision::BullletCollision() {
	auto bulletsList = bulletManager_->GetBulletList();
	for (auto bullets = bulletsList->begin(); bullets != bulletsList->end(); ++bullets) {
		length_ = Length(boss_->GetWorldPos(), bullets->GetWorldPos());

		if (length_ < (boss_->GetSize().x / 2.0f) + (bullets->GetSize().x / 2.0f)) {
			boss_->SetHp(boss_->GetHp() - 1);

			if (bullets->GetBulletType() == kBulletType::Bullet_Normal) {
				bullets->SetIsAlive(false);
				bullets->SetHp(bullets->GetHp() - 1);
			} else {
				bullets->SetHp(bullets->GetHp() - 3);
			}
		}
	}
}
