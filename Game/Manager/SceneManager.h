#pragma once
#include <memory>
#include "Base_Scene.h"
#include "Scene_Title.h"
#include "Scene_Game.h"
#include "Scene_GameOver.h"
#include "Scene_Change.h"
#include "Scene_Clear.h"

class SceneManager {

private:

	std::unique_ptr<Base_Scene> sceneArr_[4];

	int sceneNo_;

	Scene_Change* scene_change;

public:

	SceneManager();
	~SceneManager();

	void Run();

};