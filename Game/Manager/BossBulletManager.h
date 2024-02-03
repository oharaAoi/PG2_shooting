#pragma once
#include <list>
#include "BossBullet.h"

class BossBulletManager {
private:

	Vec2f playerPos_;
	std::list<BossBullet> bossBulletList_;

public:

	BossBulletManager();
	~BossBulletManager();

	void Init();
	void Update();
	void Draw();

	void BossBulletCreate(const Vec2f& bossPos);
	void PlayerPosUpdate(const Vec2f& playerPos);

	std::list<BossBullet>* GetBossBulletList() { return &bossBulletList_; }
};