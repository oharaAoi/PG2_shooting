#pragma once
#include "BaseObject.h"
#include "MapChip.h"
#include "Block.h"
#include <vector>

class Ground
:public BaseObject{

private:

	Block** blocks_;

	std::vector<std::vector<int>> mapArr_;

	int maxRow_;
	int maxCol_;

public:

	Ground();
	~Ground();

	void Init() override;
	void Update()override;
	void Draw()override;

	Vec2f GetPos(int row, int col) const { return blocks_[row][col].GetWorldPos(); }
	Vec2f GetSize(int row, int col) const { return blocks_[row][col].GetSize(); }

	RectVerf GetWorldVertex(int row, int col) { return blocks_[row][col].GetWorldVertex(); }
};