#include "BaseEntity.h"

void BaseEntity::MakeWorldMatrix(){

	worldMatrix_ = MakeAffineMatrix(scale_, theta_, worldPos_);

	worldVertex_ = MakeVertex(localVertex_, worldMatrix_);

}

void BaseEntity::MakeScreenMatrix(){

	MakeWorldMatrix();

	screenMatrix_ = MakeWvpVpMatrix(worldMatrix_, MyNovice::GetViewMatrix(),
		MyNovice::GetOrthoMatrix(), MyNovice::GetViewportMatrix());

	screenPos_ = Transform({0,0}, screenMatrix_);

	screenVertex_ = MakeVertex(localVertex_, screenMatrix_);
}
