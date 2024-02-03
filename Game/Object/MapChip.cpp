#include "MapChip.h"

std::vector<std::vector<int>> MapChip::mapChipArr_;

Vec2f MapChip::blockSize_ = { 64.0f, 64.0f };

int MapChip::maxRow_ = 0;
int MapChip::maxCol_ = 0;

MapChip::MapChip() { Init(); }

MapChip::~MapChip(){}

void MapChip::Init(){
	mapChipArr_ = loadJson_->GetMapArr();

	maxCol_ = static_cast<int>(mapChipArr_[0].size());
	maxRow_ = static_cast<int>(mapChipArr_.size());
}

void MapChip::Update(){
}
