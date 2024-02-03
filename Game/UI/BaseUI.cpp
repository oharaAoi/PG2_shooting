#include "BaseUI.h"

void BaseUI::MakeWorldMatrix(){
	worldMatrix_ = MakeAffineMatrix(scale_, theta_, pos_);

	screenVertex_.lt = Transform(localVertex_.lt, worldMatrix_);
	screenVertex_.rt = Transform(localVertex_.rt, worldMatrix_);
	screenVertex_.lb = Transform(localVertex_.lb, worldMatrix_);
	screenVertex_.rb = Transform(localVertex_.rb, worldMatrix_);
}
