#include "MyMath.h"

/*===========================================================================================
	距離に関する
============================================================================================*/
// 2点間の距離を求める
Vec2f Distance(Vec2f end, Vec2f start) {
	Vec2f result{};
	result.x = end.x - start.x;
	result.y = end.y - start.y;

	return result;
}

//2点間の距離の大きさを求める
float Length(Vec2f obj) {
	float result{};

	return result = sqrtf(powf(obj.x, 2) + powf(obj.y, 2));
}

float Length(Vec2f obj, Vec2f other) {
	Vec2f reslut{};
	float length = 0;

	reslut = Distance(obj, other);
	
	length = Length(reslut);

	return length;
}

//正規化
void Normalize(Vec2f& obj) {
	float length;
	length = Length(obj);

	if (length != 0) {
		obj.x = obj.x / length;
		obj.y = obj.y / length;
	}
}

/*===========================================================================================
	Clamp
============================================================================================*/
float Clampf(float t, float start, float end) {
	if (t < start) {
		t = start;
	} else if (t > end) {
		t = end;
	}

	return t;
}

int Clamp(int t, int max, int min){
	if (t < min) {
		t = min;
	} else if (t > max) {
		t = max;
	}

	return t;
}

/*===========================================================================================
	外積
============================================================================================*/
//外積を求め右にいるか判断する
float CrossProduct(Vec2f aVector, Vec2f bVector) {
	float dot;
	dot = aVector.x * bVector.y - aVector.y * bVector.x;

	return dot;
}

/*===========================================================================================
	Lerp
============================================================================================*/
float Lerp(float start, float end, float t){
	return (1 - t) * start + t * end;
}

Vec2f Lerp(Vec2f start, Vec2f end, float t){
	Vec2f result{};

	result.x = (1 - t) * start.x + t * end.x;
	result.y = (1 - t) * start.y + t * end.y;

	return result;
}

/*===========================================================================================
	color
============================================================================================*/
unsigned int ColorShift(unsigned int beforColor, unsigned int afterColor, float t){
	unsigned int result = 0;
	Vector4 resultColor{};

	Vector4 beforColr_ = {
		static_cast<float>(((beforColor >> 24) & 0xff)),
		static_cast<float>(((beforColor >> 16) & 0xff)),
		static_cast<float>(((beforColor >> 8) & 0xff)),
		static_cast<float>(((beforColor >> 0) & 0xff))
	};

	Vector4 afterColr_ = {
		static_cast<float>(((afterColor >> 24) & 0xff)),
		static_cast<float>(((afterColor >> 16) & 0xff)),
		static_cast<float>(((afterColor >> 8) & 0xff)),
		static_cast<float>(((afterColor >> 0) & 0xff))
	};

	resultColor = {
		Lerp(beforColr_.x, afterColr_.x, t),
		Lerp(beforColr_.y, afterColr_.y, t),
		Lerp(beforColr_.z, afterColr_.z, t),
		Lerp(beforColr_.w, afterColr_.w, t)
	};

	result += static_cast<unsigned int>(resultColor.x) << 24;
	result += static_cast<unsigned int>(resultColor.y) << 16;
	result += static_cast<unsigned int>(resultColor.z) << 8;
	result += static_cast<unsigned int>(resultColor.w) << 0;

	return result;
}

/*===========================================================================================
	各頂点
============================================================================================*/
void WorldRectVertex(RectVerf& vertex, Vec2f size) {
	vertex.lt = { -size.x / 2.0f, -size.y / 2.0f };
	vertex.rt = { size.x / 2.0f, -size.y / 2.0f };
	vertex.lb = { -size.x / 2.0f, size.y / 2.0f };
	vertex.rb = { size.x / 2.0f, size.y / 2.0f };
}

void ScreenRectVertex(RectVerf& vertex, Vec2f size) {
	vertex.lt = { -size.x / 2.0f, size.y / 2.0f };
	vertex.rt = { size.x / 2.0f, size.y / 2.0f };
	vertex.lb = { -size.x / 2.0f, -size.y / 2.0f };
	vertex.rb = { size.x / 2.0f, -size.y / 2.0f };
}

RectVerf MakeVertex(RectVerf& localVertex, Matrix3x3 matrix) {
	RectVerf result{};
	result.lt = Transform(localVertex.lt, matrix);
	result.rt = Transform(localVertex.rt, matrix);
	result.lb = Transform(localVertex.lb, matrix);
	result.rb = Transform(localVertex.rb, matrix);

	return result;
}

/*===========================================================================================
	アドレス
============================================================================================*/
VertexAddress CalcAddress(const RectVerf& vertex, const float& size){
	VertexAddress result{};

	result.lt = { static_cast<int>(vertex.lt.x / size), static_cast<int>((vertex.lt.y - 1.0f) / size) };
	result.rt = { static_cast<int>((vertex.rt.x - 1.0f) / size), static_cast<int>((vertex.rt.y - 1.0f) / size) };
	result.lb = { static_cast<int>(vertex.lb.x / size), static_cast<int>(vertex.lb.y / size) };
	result.rb = { static_cast<int>((vertex.rb.x - 1.0f) / size), static_cast<int>(vertex.rb.y / size) };

	return result;
}
