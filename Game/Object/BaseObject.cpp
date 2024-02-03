#include "BaseObject.h"

void BaseObject::BaseInit(){
	worldPos_ = { 0.0f, 0.0f };
	screenPos_ = { 0.0f, 0.0f };

	scale_ = { 1.0f, 1.0f };
	theta_ = 0.0f;

	size_ = { 64.0f, 64.0f };
	leftTop_ = { 0.0f, 0.0f };

	ScreenRectVertex(localVertex_, size_);
	worldVertex_ = localVertex_;
	screenVertex_ = localVertex_;

	MakeWorldMatrix();
	screenMatrix_ = worldMatrix_;

	color_ = 0xffffffff;
}

void BaseObject::MakeWorldMatrix(){

	worldMatrix_ = MakeAffineMatrix(scale_, theta_, worldPos_);

	worldVertex_.lt = Transform(localVertex_.lt, worldMatrix_);
	worldVertex_.rt = Transform(localVertex_.rt, worldMatrix_);
	worldVertex_.lb = Transform(localVertex_.lb, worldMatrix_);
	worldVertex_.rb = Transform(localVertex_.rb, worldMatrix_);

}

void BaseObject::MakeScreenMatrix(){

	MakeWorldMatrix();

	screenMatrix_ = MakeWvpVpMatrix(worldMatrix_, MyNovice::GetViewMatrix(),
		MyNovice::GetOrthoMatrix(), MyNovice::GetViewportMatrix());

	screenPos_ = Transform({ 0,0 }, screenMatrix_);

	screenVertex_ = MakeVertex(localVertex_, screenMatrix_);

}
