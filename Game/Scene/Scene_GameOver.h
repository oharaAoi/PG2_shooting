#pragma once
#include <SafeDelete.h>
#include "Base_Scene.h"

class Scene_GameOver
:public Base_Scene{

private:

	int GH_;

public:

	Scene_GameOver();
	~Scene_GameOver();

	void Init();
	void Update();
	void Draw();

};