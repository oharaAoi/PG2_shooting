#include "Scene_Change.h"

Scene_Change::Scene_Change() {
	Init();
}

Scene_Change::~Scene_Change()
{
}

void Scene_Change::Init() {
	for (int i = 0; i < 5; i++) {
		box_[i].pos = { -256,0 };
		box_[i].size = { 256, 720 };

		box_[i].color = 0xafeeeeff;

		box_[i].startPos = { 256.0f * (i * -1) - 256.0f  , 0 };
		box_[i].goalPos = { 256.0f * (4 - i), 0 };

		box_[i].isEnd = false;

		box_[i].move.easeT = 0;
		box_[i].move.frameCount = 0;
		box_[i].move.frameLimit = 60.0f + (i * 8);
	}

	isStart_ = false;
	isEnd_ = false;
}

void Scene_Change::Update() {
	GoIn();
	GoOut();

	if (box_[4].pos.x >= 1280) {
		isEnd_ = false;
	}
}

void Scene_Change::Draw() {
	for (int i = 0; i < 5; i++) {
		DrawBox(box_[i].pos, box_[i].size, box_[i].color, kFillModeSolid);
	}
}

void Scene_Change::GoIn() {
	if (isStart_) {
		for (int i = 0; i < 5; i++) {
			if (!box_[i].isEnd) {
				box_[i].move.frameCount++;

				box_[i].move.easeT = box_[i].move.frameCount / box_[i].move.frameLimit;
				box_[i].pos = Lerp(box_[i].startPos, box_[i].goalPos, EaseInExpo(box_[i].move.easeT));
				box_[i].color = ColorShift(0xafeeeeff, 0xffffffff, (box_[i].move.easeT));

				if (box_[i].move.frameCount == box_[i].move.frameLimit) {
					box_[i].isEnd = true;
				}

				EaseChange();
			}
		}
	}
}

void Scene_Change::GoOut() {
	if (isEnd_) {
		for (int i = 0; i < 5; i++) {

			box_[i].move.frameCount++;

			box_[i].move.easeT = box_[i].move.frameCount / box_[i].move.frameLimit;
			box_[i].pos = Lerp(box_[i].startPos, box_[i].goalPos, EaseInExpo(box_[i].move.easeT));
			box_[i].color = ColorShift(0xffffffff, 0xafeeeeff, (box_[i].move.easeT));

			if (box_[i].move.frameCount == box_[i].move.frameLimit) {
				box_[i].isEnd = false;
			}

		}
	}
}

void Scene_Change::EaseChange() {
	if (!box_[4].isEnd) {
		return;
	}

	for (int i = 0; i < 5; i++) {
		box_[i].startPos = box_[i].goalPos;
		box_[i].goalPos = { 256.0f * (i * -1) + 1280.0f , 0 };
		box_[i].move.frameCount = 0;
		Base_Scene::SetSceneChange(true);
	}

	isEnd_ = true;
	isStart_ = false;
}
