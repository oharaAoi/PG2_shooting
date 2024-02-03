#pragma once
#include <json.hpp>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

#include <vector>
#include "MyVector2.h"

using json = nlohmann::json;

struct EntityDate {
	Vec2f worldPos;
	Vec2f scale;
	float theta;

	Vec2f size;
	Vec2f leftTop;

	Vec2f velocity;
	Vec2f accelation;
};

struct UIDate {
	Vec2f worldPos;
	Vec2f scale;
	float theta;

	Vec2f size;
	Vec2f leftTop;
};

class LoadJson{

private:

	//シングルトンにする(他クラスでインスタンスを作成できない)
	LoadJson() {};
	~LoadJson() {};

	// stage
	std::vector<std::vector<int>> mapArr_;

	static EntityDate entityDate_;
	static  UIDate UIDate_;

	// 敵のファイル名
	static std::string snakeFile_;
	static std::string bardFile_;

public:

	// コピーコンストラクタの禁止
	LoadJson(const LoadJson& obj) = delete;
	LoadJson operator + (const LoadJson& obj) = delete;

	static LoadJson* GetInstance();

	void Init();

	// ステージの読み込み
	void LoadStageDate(std::string fileName);

	static void LoadEntityStatus(std::string fileName);
	static void LoadUiStatus(std::string fileName);

	// アクセッサ
	std::vector<std::vector<int>> GetMapArr() { return mapArr_; }

	static EntityDate GetEntityDate() { return entityDate_; }
	static UIDate GetUIDate() { return UIDate_; }

	// ファイル
	static std::string GetSnakeFile() { return snakeFile_; }
	static std::string GetBardFile() { return bardFile_; }

};

