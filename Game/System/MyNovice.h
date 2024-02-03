#pragma once
#include <Novice.h>
#include "InputManager.h"
#include "Camera.h"

class MyNovice{
private:

	static InputManager* input_;
	static Camera* camera_;
	
public:

	static void Updata();

	// input -----------------------------
	/// keys
	static bool IsTriggerKey(int DIK) { return input_->IsTriggerKey(DIK); }
	static bool IsPressKey(int DIK) { return input_->IsPressKeys(DIK); }
	static bool IsReleseKey(int DIK){ return input_->IsReleseKeys(DIK); }

	// mouse
	static bool IsTriggerMouse(int buttonNum) { return input_->IsTriggerMouse(buttonNum); }
	static bool IsPressMouse(int buttonNum) { return input_->IsPressMouse(buttonNum); }
	static Vec2f GetMousePosf() { return camera_->Unproject(input_->GetMousePosf()); }

	// コントローラー
	static bool IsTriggerButton(PadButton button) { return input_->IsTriggerButton(button); }
	static bool IsPressButton(PadButton button) { return input_->IsPressButton(button); }
	static bool IsReleseButton(PadButton button) { return input_->IsReleseButton(button); }
	static Vec2f GetAnalogLeft() { return input_->GetAngleInputLeft(); }
	static Vec2f GetAnalogRight() { return input_->GetAngleInputRight(); }

	// camera -----------------------------
	static Matrix3x3 GetViewMatrix() { return camera_->GetViewMatrix(); }
	static Matrix3x3 GetOrthoMatrix() { return camera_->GetOrthoMatrix(); }
	static Matrix3x3 GetViewportMatrix() { return camera_->GetViewportMatrix(); }

	static Matrix3x3 MakeWvpVpMatrix(Matrix3x3 matrix) { return camera_->MakeWvpVpMatrix(matrix); }

};

