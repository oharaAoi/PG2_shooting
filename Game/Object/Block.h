#pragma once
#include "BaseObject.h"
#include "MapChip.h"

class Block
	:public BaseObject {

private:

	int GH_;

public:

	Block();
	~Block();

	void Init();
	void Update();
	void Draw();

	void SetWorldPos(Vec2f pos) { worldPos_ = pos; }

	Vec2f GetWorldPos() const { return worldPos_; }
	Vec2f GetSize() const { return size_; }
	RectVerf GetWorldVertex() const { return worldVertex_; }

};