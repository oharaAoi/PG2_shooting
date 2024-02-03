#pragma once
#include <list>
#include "Enemy.h"
#include "MyNovice.h"

#ifdef _DEBUG
#include "ImGuiManager.h"
#endif

class EnemyManager{
private:

	std::list<Enemy> enemyList_;

	// count ---------------------------
	int enemyPopCount_;

	static int totalDownCount_;

	bool isEnemysAllDown_;

public:

	EnemyManager();
	~EnemyManager();

	void Init();
	void Update();
	void Draw();

	// user method
	void EnemyPop();

	// accesser
	void SetIsEnemysAllDown(const bool& isDown) { isEnemysAllDown_ = isDown; }
	static int GetTotalDownCount() { return totalDownCount_; }

	bool GetIsEnemysAllDown() const { return isEnemysAllDown_; }
	std::list<Enemy>* GetEnemyList() { return &enemyList_; }
};