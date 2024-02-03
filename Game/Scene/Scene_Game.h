#pragma once
#include <SafeDelete.h>
#include "Base_Scene.h"
#include "LoadJson.h"

// entity -----
#include "player.h"
#include "Boss.h"

// object -----
#include "MapChip.h"
#include "Ground.h"

// manager
#include "CollisionManager.h"
#include "EnemyManager.h"
#include "BaseUI.h"

// UI
#include "EnemyDownUI.h"
#include "BossUI.h"

static const int kUIMax = 2;

class Scene_Game
	:public Base_Scene {

private:

	unsigned int color_;
	bool isBlackOut_;
	EaseParam blackOut_;

	bool iswhiteOut_;
	EaseParam whiteOut_;

	int GH_;

	Player* player_;
	Boss* boss_;
	Ground* ground_;

	MapChip* mapChip_;

	CollisionManager* collisionManager_;
	EnemyManager* enemyManager_;

	BaseUI* ui_[kUIMax];

	LoadJson* loadJson_ = LoadJson::GetInstance();

public:

	Scene_Game();
	~Scene_Game();

	void Init();
	void Update();
	void Draw();

	void BlackOut();
	void WhiteOut();
};