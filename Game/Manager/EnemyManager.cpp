#include "EnemyManager.h"

int EnemyManager::totalDownCount_ = 0;

EnemyManager::EnemyManager(){
	Init();
}

EnemyManager::~EnemyManager(){
}

/*===========================================================================================
	初期化関数
============================================================================================*/
void EnemyManager::Init(){
	enemyPopCount_ = 0;
	totalDownCount_ = 0;

	isEnemysAllDown_ = false;
}

/*===========================================================================================
	更新処理関数
============================================================================================*/
void EnemyManager::Update(){
	enemyPopCount_++;

	if (enemyPopCount_ > 180) {
		EnemyPop();
		enemyPopCount_ = 0;
	}

	for (auto iter = enemyList_.begin(); iter != enemyList_.end();) {
		if (iter->GetIsAlive()) {
			iter->Update();
			iter++;

		} else {
			iter = enemyList_.erase(iter);
			totalDownCount_++;
		}
	}

	if (totalDownCount_ >= 15) {
		isEnemysAllDown_ = true;
	}
}

/*===========================================================================================
	描画関数
============================================================================================*/
void EnemyManager::Draw(){
	for (auto iter = enemyList_.begin(); iter != enemyList_.end();) {
		iter->Draw();
		iter++;
	}
}

/*===========================================================================================
	敵を生成
============================================================================================*/
void EnemyManager::EnemyPop(){
	Enemy enemys;
	enemyList_.push_back(enemys);
}
