#pragma once
#include "MyMath.h"
#include "MyVector2.h"
#include "Matrix.h"
#include "RectVertex.h"
#include "AddressStruct.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <Vector4.h>

/*---------------------------------------------*/
//2点間の距離を求める
Vec2f Distance(Vec2f obj, Vec2f other);

//2点間の距離の大きさを求める
float Length(Vec2f obj);

// 2点間の距離の大きさを求める(当たり判定とかに使う)
float Length(Vec2f obj, Vec2f other);

//正規化
void Normalize(Vec2f& obj);

/*---------------------------------------------*/
// クランプ
float Clampf(float t, float start, float end);
int Clamp(int t, int max, int min);

/*---------------------------------------------*/
//外積
float CrossProduct(Vec2f aVector, Vec2f bVector);

/*---------------------------------------------*/
// 線形補完
float Lerp(float start, float end, float t);

Vec2f Lerp(Vec2f start, Vec2f end, float t);

/*---------------------------------------------*/
// カラーシフト
unsigned int ColorShift(unsigned int beforColor, unsigned int afterColor, float t);

/*---------------------------------------------*/
// 各頂点の計算
void WorldRectVertex(RectVerf& vertex, Vec2f size);
void ScreenRectVertex(RectVerf& vertex, Vec2f size);

/*---------------------------------------------*/
// 座標系の変換
RectVerf MakeVertex(RectVerf& localVertex, Matrix3x3 matrix);

/*---------------------------------------------*/
// アドレス
VertexAddress CalcAddress(const RectVerf& address, const float& size);