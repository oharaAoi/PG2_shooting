#include "SceneManager.h"

SceneManager::SceneManager(){
	// 配列にそれぞれのシーンを格納
	// 必要に応じてそれぞれのクラスにアクセスできる
	sceneArr_[SCENE_TITLE] = std::make_unique<Scene_Title>();
	sceneArr_[SCENE_GAME] = std::make_unique<Scene_Game>();
	sceneArr_[SCENE_GAMEOVER] = std::make_unique<Scene_GameOver>();
	sceneArr_[SCENE_CLEAR] = std::make_unique<Scene_Clear>();

	// タイトルで初期化
	sceneNo_ = SCENE_TITLE;
	sceneArr_[sceneNo_]->Init();

	scene_change = new Scene_Change();
}

SceneManager::~SceneManager(){
	SafeDelete(scene_change);
}

void SceneManager::Run(){
	if (sceneArr_[sceneNo_]->GetIsSceneTransition()) {
		scene_change->Init();
		scene_change->SetIsStart(true);
		sceneArr_[sceneNo_]->SetIsSceneTransition(false);
	}

	if (scene_change->GetIsStart()) {
		scene_change->Update();
		sceneArr_[sceneNo_]->Draw();
		scene_change->Draw();
		return;
	}

	// 今のシーンを取得
	sceneNo_ = sceneArr_[sceneNo_]->GetSceneNo();

	// シーンを切り替えるフラグがtrueだったら
	if (sceneArr_[sceneNo_]->GetSceneChange() == true) {
		sceneArr_[sceneNo_]->Init();
		sceneArr_[sceneNo_]->SetSceneChange(false);
		return;
	}

	// それぞれのクラスのUpdateに入る
	sceneArr_[sceneNo_]->Update();

	sceneArr_[sceneNo_]->Draw();

	if (scene_change->GetIsEnd()) {
		scene_change->Update();
		scene_change->Draw();
	}


}
