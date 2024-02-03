#pragma once
#include "MyNovice.h"

enum SceneNum {
	SCENE_TITLE,
	SCENE_GAME,
	SCENE_GAMEOVER,
	SCENE_CLEAR
};

class Base_Scene{
protected:

	static int sceneNo_;

	static bool isSceneChange_;

	static bool isSceneTransition_;

public:

	virtual ~Base_Scene() {};

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	static int GetSceneNo() { return sceneNo_; }

	static void SetSceneChange(bool isChange) { isSceneChange_ = isChange; }
	static bool GetSceneChange() { return isSceneChange_; }

	static void SetIsSceneTransition(bool isTansition) { isSceneTransition_ = isTansition; }
	static bool GetIsSceneTransition() { return isSceneTransition_; }

};

