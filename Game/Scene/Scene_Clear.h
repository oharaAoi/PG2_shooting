#pragma once
#include <SafeDelete.h>
#include "Base_Scene.h"
class Scene_Clear
    :public Base_Scene {
private:

    int GH_;

public:

    Scene_Clear();
    ~Scene_Clear();

    void Init()override;
    void Update()override;
    void Draw()override;
};

