#pragma once
#include "player.h"
#include "Boss.h"

class PlayerCollision {
private:

	float length_;

	Player* player_;
	Boss* boss_;

	BulletManager* bulletManager_;
	BossBulletManager* bossBulletManager_;

public:

	PlayerCollision(Player* player, Boss* boss);
	~PlayerCollision();

	void Init(Player* player, Boss* boss);
	void Update();

	// user method
	void BulletCollision();
	void BossBulletCollision();

	void PlayerInBubble();


};