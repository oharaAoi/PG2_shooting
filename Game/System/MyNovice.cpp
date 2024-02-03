#include "MyNovice.h"

InputManager* MyNovice::input_ = new InputManager();
Camera* MyNovice::camera_ = new Camera();

void MyNovice::Updata(){
	input_->Update();
	camera_->Update();
}
