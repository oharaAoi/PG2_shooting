#pragma once
#include <SafeDelete.h>

// collision -----
#include "GroundCollision.h"
#include "EnemyCollision.h"
#include "PlayerCollision.h"
#include "BossCollision.h"

class CollisionManager{

private:

	Player* player_;
	Boss* boss_;
	Ground* ground_;
	EnemyManager* enemyManager_;

	GroundCollision* groundCollision_;
	EnemyCollision* enemyCollision_;
	PlayerCollision* playerCollision_;
	BossCollision* bossCollision_;

public:

	CollisionManager(Player* player, EnemyManager* enemyManager, Boss* boss, Ground* ground);
	~CollisionManager();

	void Init(Player* player, EnemyManager* enemyManager, Boss* boss, Ground* ground);
	void Update();

};

