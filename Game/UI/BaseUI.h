#pragma once
#include "MyNovice.h"
#include "MyVector2.h"
#include "Matrix.h"
#include "RectVertex.h"
#include "MyMath.h"
#include "EaseStruct.h"
#include "Easing.h"
#include "Draw.h"

class BaseUI{

protected:

	Vec2f pos_;
	Vec2f scale_;
	float theta_;

	Vec2f size_;
	Vec2f leftTop_;

	// 各頂点
	RectVerf localVertex_;
	RectVerf screenVertex_;

	// 行列
	Matrix3x3 worldMatrix_;

	unsigned int color_;

	int GH_;

public:

	BaseUI() = default;
	virtual~BaseUI() = default;

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	void MakeWorldMatrix();


};