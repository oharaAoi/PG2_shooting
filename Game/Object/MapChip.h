#pragma once
#include <vector>
#include "MyVector2.h"
#include "LoadJson.h"

enum ChipType {
	NONE,
	GROUND,
};

class MapChip{
private:

	// 配列
	static std::vector<std::vector<int>> mapChipArr_;

	// ブロックの大きさ
	static Vec2f blockSize_;

	static int maxRow_;
	static int maxCol_;

	LoadJson* loadJson_ = LoadJson::GetInstance();

public:

	MapChip();
	~MapChip();

	void Init();
	void Update();

	static int GetRow() { return maxRow_;}
	static int GetCol() { return maxCol_; }

	static Vec2f GetBlockSize() { return blockSize_; }

	static std::vector<std::vector<int>> GetMapChipArr() { return  mapChipArr_; }

};

