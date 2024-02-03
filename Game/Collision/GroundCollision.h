#pragma once
#include "player.h"
#include "Ground.h"
#include "BulletManager.h"

class GroundCollision {
private:

	Player* player_;
	Ground* ground_;

	BulletManager* bulletManager_;

	Vec2f playerPos_;
	Vec2f playerVertex_;
	Vec2f blocksPos_;
	Vec2f distance_;

public:

	GroundCollision(Player* player, Ground* ground);
	~GroundCollision();

	void Init(Player* player, Ground* ground);
	void Update();

	void PlayerGroundCollision();
	void BulletGroundCollision();

};