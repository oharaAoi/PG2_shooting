#include "LoadJson.h"

EntityDate LoadJson::entityDate_;
UIDate LoadJson::UIDate_;

LoadJson* LoadJson::GetInstance() {
	static LoadJson instance;
	return &instance;
}

std::string LoadJson::snakeFile_ = "./Resources/json/snakeDate.json";
std::string LoadJson::bardFile_ = "./Resources/json/bardDate.json";

void LoadJson::Init(){
	mapArr_.clear();
}

/*=================================================
	// ステージのデータを読み込む
==================================================*/
/// fileのパスを引数に指定して読み込む
void LoadJson::LoadStageDate(std::string fileName){
	json mapDate;

	std::ifstream inputFile(fileName);

	if (inputFile.is_open()) {
		inputFile >> mapDate;

		mapArr_.clear();
		// loadjsonクラスのmapArrの中にデータを入れる
		// それをゲッターを通じて取得
		mapArr_ = mapDate["map"]["tiles"];

		// ワールド座標系にしているため行を反転させる(もしかしたらいらないかも)
		std::reverse(mapArr_.begin(), mapArr_.end());

		// ファイルを閉じる
		inputFile.close();
	}
}

void LoadJson::LoadEntityStatus(std::string fileName){
	json entityDate;

	std::ifstream inputFile(fileName);

	if (inputFile.is_open()) {
		inputFile >> entityDate;

		if (entityDate.contains("pos")) {
			entityDate_.worldPos = {
				entityDate["pos"]["x"],
				entityDate["pos"]["y"],
			};
		}

		if (entityDate.contains("scale")) {
			entityDate_.scale = {
				entityDate["scale"]["x"],
				entityDate["scale"]["y"],
			};
		}

		if (entityDate.contains("theta")) {
			entityDate_.theta = entityDate["theta"];	
		}

		if (entityDate.contains("size")) {
			entityDate_.size = {
				entityDate["size"]["x"],
				entityDate["size"]["y"],
			};
		}

		if (entityDate.contains("leftTop")) {
			entityDate_.leftTop = {
				entityDate["leftTop"]["x"],
				entityDate["leftTop"]["y"],
			};
		}

		if (entityDate.contains("velocity")) {
			entityDate_.velocity = {
				entityDate["velocity"]["x"],
				entityDate["velocity"]["y"],
			};
		}
		
		if (entityDate.contains("accelation")) {
			entityDate_.accelation = {
				entityDate["accelation"]["x"],
				entityDate["accelation"]["y"],
			};
		}

		// ファイルを閉じる
		inputFile.close();
	}
}

void LoadJson::LoadUiStatus(std::string fileName) {
	json UIDate;

	std::ifstream inputFile(fileName);

	if (inputFile.is_open()) {
		inputFile >> UIDate;

		if (UIDate.contains("pos")) {
			UIDate_.worldPos = {
				UIDate["pos"]["x"],
				UIDate["pos"]["y"],
			};
		}

		if (UIDate.contains("scale")) {
			UIDate_.scale = {
				UIDate["scale"]["x"],
				UIDate["scale"]["y"],
			};
		}

		if (UIDate.contains("theta")) {
			UIDate_.theta = UIDate["theta"];
		}

		if (UIDate.contains("size")) {
			UIDate_.size = {
				UIDate["size"]["x"],
				UIDate["size"]["y"],
			};
		}

		if (UIDate.contains("leftTop")) {
			UIDate_.leftTop = {
				UIDate["leftTop"]["x"],
				UIDate["leftTop"]["y"],
			};
		}

		// ファイルを閉じる
		inputFile.close();
	}
}

