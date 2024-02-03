#include "BossBulletManager.h"

BossBulletManager::BossBulletManager(){
	Init();
}

BossBulletManager::~BossBulletManager(){
}

void BossBulletManager::Init(){
}

void BossBulletManager::Update(){
	for (auto iter = bossBulletList_.begin(); iter != bossBulletList_.end();) {
		if (iter->GetIsAlive()) {
			iter->Update();
			iter++;

		} else {
			iter = bossBulletList_.erase(iter);
		}
	}
}

void BossBulletManager::Draw(){
	for (auto iter = bossBulletList_.begin(); iter != bossBulletList_.end();) {
		iter->Draw();
		iter++;
	}
}

void BossBulletManager::BossBulletCreate(const Vec2f& bossPos) {
	BossBullet newBullet(bossPos, playerPos_);
	bossBulletList_.push_back(newBullet);
}

void BossBulletManager::PlayerPosUpdate(const Vec2f& playerPos){
	playerPos_ = playerPos;
}
