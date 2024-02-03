#pragma once
#include <Novice.h>
#include "MyVector2.h"
#include "MyMath.h"
#include "RectVertex.h"

void DrawSprite(Vec2f centerPos, float width, float height, Vec2f scall, int GH, unsigned int color);

void DrawBox(const Vec2f& leftTop, const Vec2f& size, const  unsigned int& color, const FillMode& mode);

void DrawQuad(Vec2f pos, Vec2f size, Vec2f lt,int gh, unsigned int color);

void DrawQuad(RectVerf vertex, Vec2f size, Vec2f lt, int gh, unsigned int color);

void PlayAudio(int& voiceHandle, int soundHandle, float soundVolume, bool isLoop);