#pragma once
#include "SafeDelete.h"
#include "MyNovice.h"
#include "MyVector2.h"
#include "Matrix.h"
#include "RectVertex.h"
#include "MyMath.h"
#include "Draw.h"
#include "SoundStruct.h"
#include "EaseStruct.h"
#include "AddressStruct.h"

class BaseEntity{

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

	Vec2f velocity_;
	Vec2f accelation_;
	
	// 各頂点
	RectVerf localVertex_;
	RectVerf worldVertex_;
	RectVerf screenVertex_;

	// 行列
	Matrix3x3 worldMatrix_;
	Matrix3x3 screenMatrix_;

	// 
	unsigned int color_;

	// 
	bool isAlive_;

public:

	BaseEntity() = default;
	virtual ~BaseEntity() = default;

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	// ワールド行列の作成
	void MakeWorldMatrix();

	// スクリーン行列の作成
	void MakeScreenMatrix();

	Vec2f GetWorldPos() const { return worldPos_; }

};