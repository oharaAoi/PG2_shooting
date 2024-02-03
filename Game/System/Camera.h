#pragma once
#include <Novice.h>
#include "Matrix.h"
#include "MyVector2.h"
#include "MyMath.h"
#include "EaseStruct.h"
#include "MyRandom.h"
//#include "MyMath.h"

class Camera
{

private:

	Vec2f pos_;

	float left_;
	float top_;

	float right_;
	float bottom_;

	float width_;
	float height_;

	Matrix3x3 cameraWorldMatrix{};

	//ビュー行列
	Matrix3x3 viewMatrix{};
	//正射影行列
	Matrix3x3 orthoMatrix{};
	//ビューポート行列
	Matrix3x3 viewportMatrix{};
	//結合行列
	Matrix3x3 wvpVpMatrix{};

	//逆ビュー行列
	Matrix3x3 InverseViewMatrix{};
	//逆正射影行列
	Matrix3x3 InverseOrthoMatrix{};
	//逆ビューポート行列
	Matrix3x3 InverseViewportMatrix{};

	// カメラ追いするための変数
	EaseParam camera_;

	bool isShake_;
	int shakeTime_;
	Vec2f shakePos_;
	Vec2 shakeLimit_;

public:

	Camera();

	void Init();
	void Update();
	void Draw();

	void CameraMove(Vec2f pos);
	void CameraShake();

	Vec2f Unproject(Vec2f screenCoordinates);

	Matrix3x3 MakeWvpVpMatrix(Matrix3x3 matrix);

	Matrix3x3 GetWvpVpMatrix() const { return wvpVpMatrix; }

	Matrix3x3 GetViewMatrix()const { return viewMatrix; }
	Matrix3x3 GetOrthoMatrix()const { return orthoMatrix; }
	Matrix3x3 GetViewportMatrix()const { return viewportMatrix; }

	void SetIsShake(bool isShake) { isShake_ = isShake; }
	void SetShakeTime(int time) { shakeTime_ = time; }

};

