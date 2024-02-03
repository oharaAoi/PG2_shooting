#pragma once
#include "MyNovice.h"
#include "MyVector2.h"
#include "Matrix.h"
#include "RectVertex.h"
#include "Draw.h"
#include "MyMath.h"

class BaseObject{
protected:

	/// <summary>
	/// このベースを継承すれば基本のメンバ変数は各クラスで作る必要がない
	/// </summary>

	Vec2f worldPos_;
	Vec2f screenPos_;
	Vec2f scale_;
	float theta_;

	Vec2f size_;
	Vec2f leftTop_;
	float radius_;

	// 各頂点
	RectVerf localVertex_;
	RectVerf worldVertex_;
	RectVerf screenVertex_;

	// 行列
	Matrix3x3 worldMatrix_;
	Matrix3x3 screenMatrix_;

	// 
	unsigned int color_;

public:

	BaseObject() = default;
	virtual ~BaseObject() = default;

	void BaseInit();
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	// ワールド行列の作成
	void MakeWorldMatrix();

	// スクリーン行列の作成
	void MakeScreenMatrix();

	void SetWorldPos(Vec2f pos) { worldPos_ = pos; }

	Vec2f GetWorldPos() const { return worldPos_; }

};

