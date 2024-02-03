#pragma once
#include <SafeDelete.h>
#include "BaseEntity.h"
#include "LoadJson.h"

// lib
#include "MyRandom.h"

enum EnemyType {
	Snake = 1,
	Bard
};

enum EnemyPopSide {
	Side_Left,
	Side_Right
};

class Enemy
:public BaseEntity{

private:

	int randomFileNum_;
	int randomPopSide_;

	int GH_;

	EnemyType enemyType_;

	int hp_;
	int initHp_;

	// 鳥の変数
	float keepFirstPosY_;
	float flyTheta_;
	float amplitude_;

	// hp表記
	Vec2f uiLeftTop_;
	Vec2f uiSize_;
	Vec2f drawUiSize_;

public:

	Enemy();
	~Enemy();

	void Init();
	void Update();
	void Draw();

	// user method
	void Move();
	void SnakeMove();
	void BardMove();
	void LoadFile(int num);

	// accesser
	void SetIsAlive(const bool& isAlive) { isAlive_ = isAlive; }
	void SetHp(const int& hp) { hp_ = hp; }

	int GetHp() const { return hp_; }
	bool GetIsAlive() const { return isAlive_; }
	Vec2f GetWorldPos() const { return worldPos_; }
	Vec2f GetSize() const { return size_; }

};