#pragma once
#include <list>
#include "Bullet.h"
#include "BossBullet.h"

class BulletManager {
private:

	Vec2f playerPos_;

	std::list<Bullet> bulletList_;

public:

	BulletManager();
	~BulletManager();

	void Init();
	void Update(const Vec2f& pos);
	void Draw();

	void BulletCreate(const Vec2f& pos, const int& count);

	// accesser 
	std::list<Bullet>* GetBulletList() { return &bulletList_; }
};