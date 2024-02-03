#pragma once
#include "BaseUI.h"
#include "LoadJson.h"
#include "Boss.h"

class BossUI 
	:public BaseUI {
private:

	Vec2f drawSize_;

public:

	BossUI();
	~BossUI();

	void Init();
	void Update();
	void Draw();

};