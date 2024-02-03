#pragma once
#include <SafeDelete.h>
#include "Base_Scene.h"

class Scene_Title
    :public Base_Scene {

private:

    int GH_;

public:

    Scene_Title();
    ~Scene_Title();

    void Init()override;
    void Update()override;
    void Draw()override;

};