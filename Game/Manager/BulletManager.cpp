#include "BulletManager.h"

BulletManager::BulletManager(){
	Init();
}

BulletManager::~BulletManager(){
}

void BulletManager::Init(){
}

void BulletManager::Update(const Vec2f& pos){
	playerPos_ = pos;

	for (auto iter = bulletList_.begin(); iter != bulletList_.end();) {
		if (iter->GetIsAlive()) {
			iter->Update();
			iter++;

		} else {
			iter = bulletList_.erase(iter);
		}
	}
}

void BulletManager::Draw(){
	for (auto iter = bulletList_.begin(); iter != bulletList_.end();) {
		iter->Draw();
		iter++;
	}
}

void BulletManager::BulletCreate(const Vec2f& pos, const int& count){
	Bullet newBullet(pos, count);
	bulletList_.push_back(newBullet);
}
