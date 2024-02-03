#include "Ground.h"

Ground::Ground(){
	Init();
}

Ground::~Ground(){
	for (int i = 0; i < MapChip::GetRow(); i++) {
		delete[] blocks_[i];
	}
}

/*=========================================
	初期化関数
==========================================*/
void Ground::Init(){
	mapArr_ = MapChip::GetMapChipArr();

	maxRow_ = MapChip::GetRow();
	maxCol_ = MapChip::GetCol();

	blocks_ = new Block * [maxRow_];
	for (int i = 0; i < maxRow_; i++) {
		blocks_[i] = new Block[maxCol_];
	}

	for (int row = 0; row < maxRow_; row++) {
		for (int col = 0; col < maxCol_; col++) {
			if (MapChip::GetMapChipArr()[row][col] == GROUND) {
				blocks_[row][col].SetWorldPos({
					64.0f * col + 32.0f,
					64.0f * row + 32.0f
				});
			}
		}
	}
}

/*=========================================
	更新関数
==========================================*/
void Ground::Update(){
	for (int row = 0; row < maxRow_; row++) {
		for (int col = 0; col < maxCol_; col++) {
			blocks_[row][col].Update();
		}
	}
}

/*=========================================
	描画関数
==========================================*/
void Ground::Draw(){
	for (int row = 0; row < maxRow_; row++) {
		for (int col = 0; col < maxCol_; col++) {
			blocks_[row][col].Draw();
		}
	}
}