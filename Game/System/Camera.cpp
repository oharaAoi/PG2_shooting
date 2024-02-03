#include "Camera.h"

Camera::Camera() {
	Init();
}

void Camera::Init() {

	pos_.x = 640.0f;
	pos_.y = 360.0f ;

	left_ = -640.0f;
	top_ = 360.0f;

	right_ = 640.0f;
	bottom_ = -360.0f;

	width_ = 1280.0f;
	height_ = 720.0f;

	cameraWorldMatrix.m[0][0] = 1.0f;
	cameraWorldMatrix.m[1][1] = 1.0f;
	cameraWorldMatrix.m[2][0] = pos_.x;
	cameraWorldMatrix.m[2][1] = pos_.y;
	cameraWorldMatrix.m[2][2] = 1;

	viewMatrix = Inverse(cameraWorldMatrix);
	//カメラの正射影行列を作成
	orthoMatrix = MakeOrthographicMatrix(left_, top_, right_, bottom_);
	//カメラのビューポート行列を作成
	viewportMatrix = MakeViewportMatrix(0.0f, 0.0f, width_, height_);

	camera_.frameCount = 0;
	camera_.easeT = 0;
	camera_.frameLimit = 60;

	isShake_ = false;
	shakeTime_ = 0;

	shakePos_ = { 0,0 };
	shakeLimit_ = { 5 , -5 };

}

void Camera::Update(){

	if (isShake_) {
		shakeTime_++;
		CameraShake();

		float t = float(shakeTime_) / 60.0f;

		shakeLimit_.x = static_cast<int>(Lerp(20, 1, t));
		shakeLimit_.y = static_cast<int>(Lerp(-20, -1, t));

		if (shakeTime_ > 60) {
			isShake_ = false;
			shakeTime_ = 0;
		}
	}

	cameraWorldMatrix.m[0][0] = 1;
	cameraWorldMatrix.m[1][1] = 1;
	cameraWorldMatrix.m[2][0] = pos_.x + shakePos_.x;
	cameraWorldMatrix.m[2][1] = pos_.y + shakePos_.y;
	cameraWorldMatrix.m[2][2] = 1;

	//カメラのビュー行列を作成
	viewMatrix = Inverse(cameraWorldMatrix);
	//カメラの正射影行列を作成
	orthoMatrix = MakeOrthographicMatrix(left_, top_, right_, bottom_);
	//カメラのビューポート行列を作成
	viewportMatrix = MakeViewportMatrix(0.0f, 0.0f, width_, height_);

	//カメラのビュー行列を作成
	InverseViewMatrix = Inverse(viewMatrix);
	//カメラの正射影行列を作成
	InverseOrthoMatrix = Inverse(orthoMatrix);
	//カメラのビューポート行列を作成
	InverseViewportMatrix = Inverse(viewportMatrix);

	shakePos_ = { 0,0 };

}

void Camera::CameraMove(Vec2f pos) {
	camera_.frameCount++;
	camera_.easeT = camera_.frameCount / camera_.frameLimit;

	pos_ = Lerp(pos_, pos, 0.1f);
}

void Camera::CameraShake(){
	Random(shakePos_, shakeLimit_.x, shakeLimit_.y);
}

Matrix3x3 Camera::MakeWvpVpMatrix(Matrix3x3 matrix) {
	Matrix3x3  result{};

	//カメラのビュー行列を作成
	viewMatrix = Inverse(cameraWorldMatrix);
	//カメラの正射影行列を作成
	orthoMatrix = MakeOrthographicMatrix(left_, top_, right_, bottom_);
	//カメラのビューポート行列を作成
	viewportMatrix = MakeViewportMatrix(0.0f, 0.0f, width_, height_);

	//行列を結合する
	wvpVpMatrix = Multiply(matrix, viewMatrix);
	wvpVpMatrix = Multiply(wvpVpMatrix, orthoMatrix);
	result = Multiply(wvpVpMatrix, viewportMatrix);

	return  result;
}

void Camera::Draw() {
	/*Novice::ScreenPrintf(10, 400, "cameraPos.x:%f", pos_.x);
	Novice::ScreenPrintf(10, 420, "cameraPos.y:%f", pos_.y);*/
}

Vec2f Camera::Unproject(Vec2f screenCoordinates){
	// スクリーン座標を正規化デバイス座標系に変換
	/*Vec2f normalizedDeviceCoordinates = Vec2f(
		2.0f * ((float)screenCoordinates.x / width_) - 1.0f,
		1.0f - 2.0f * ((float)screenCoordinates.y / height_)
	);*/

	Vec2f normalizedDeviceCoordinates = { 0.0f, 0.0f };

	normalizedDeviceCoordinates = Transform(screenCoordinates, InverseViewportMatrix);

	Vec2f viewCoord = Transform(normalizedDeviceCoordinates, InverseOrthoMatrix);

	Vec2f  worldCoord = Transform(viewCoord, InverseViewMatrix);

	return  worldCoord;
}
