#pragma once
#include "MyNovice.h"
#include "MyVector2.h"
#include "EaseStruct.h"
#include "Easing.h"
#include "MyMath.h"
#include "Draw.h"
#include "Base_Scene.h"

class Scene_Change {
private:

	struct Base {
		Vec2f pos;
		Vec2f size;
		unsigned int color;

		Vec2f startPos;
		Vec2f goalPos;

		bool isEnd;

		EaseParam move;
	};

	Base box_[5];

	bool isStart_;
	bool isEnd_;

public:
	Scene_Change();
	~Scene_Change();

	void Init();
	void Update();
	void Draw();

	void GoIn();
	void GoOut();

	void EaseChange();

	void SetIsStart(const bool& isStart) { isStart_ = isStart; }
	bool GetIsStart() const { return isStart_; }

	bool GetIsEnd() const { return isEnd_; }
};