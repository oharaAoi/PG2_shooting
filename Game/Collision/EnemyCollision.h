#pragma once
#include "player.h"
#include "EnemyManager.h"
#include "MyMath.h"

class EnemyCollision {
private:

	float length_;

	Player* player_;
	EnemyManager* enemyManager_;
	BulletManager* bulletManager_;

public:

	EnemyCollision(Player* player, EnemyManager* enemyManger);
	~EnemyCollision();

	void Init(Player* player, EnemyManager* enemyManger);
	void Update();

	void BulletCollision();
	void PlayerCollision();

};