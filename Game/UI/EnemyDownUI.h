#pragma once
#include "BaseUI.h"
#include "LoadJson.h"
#include "EnemyManager.h"

class EnemyDownUI
	:public BaseUI {

private:

	Vec2f drawSize_;

public:

	EnemyDownUI();
	~EnemyDownUI();

	void Init() override;
	void Update() override;
	void Draw() override;

};