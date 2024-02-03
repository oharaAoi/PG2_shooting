#include "Draw.h"

void DrawSprite(Vec2f centerPos, float width, float height, Vec2f scall, int GH, unsigned int color) {
	Novice::DrawSprite(
		static_cast<int>(centerPos.x - width / 2),
		static_cast<int>(centerPos.y - height / 2),
		GH,
		scall.x,
		scall.y,
		0.0f,
		color
	);
}

void DrawBox(const Vec2f& leftTop, const Vec2f& size, const  unsigned int& color, const FillMode& mode){
	Novice::DrawBox(
		static_cast<int>(leftTop.x),
		static_cast<int>(leftTop.y),
		static_cast<int>(size.x),
		static_cast<int>(size.y),
		0.0f,
		color,
		mode
	);
}

void DrawQuad(Vec2f pos, float width, float height, Vec2f lt,
	int gh, unsigned int color) {
	Novice::DrawQuad(
		static_cast<int>(floorf(pos.x - (width / 2))),
		static_cast<int>(floorf(pos.y - (height / 2))),
		static_cast<int>(floorf(pos.x + (width / 2))),
		static_cast<int>(floorf(pos.y - (height / 2))),
		static_cast<int>(floorf(pos.x - (width / 2))),
		static_cast<int>(floorf(pos.y + (height / 2))),
		static_cast<int>(floorf(pos.x + (width / 2))),
		static_cast<int>(floorf(pos.y + (height / 2))),
		static_cast<int>(lt.x),
		static_cast<int>(lt.y),
		static_cast<int>(width),
		static_cast<int>(height),
		gh,
		color
	);
}

void DrawQuad(Vec2f pos, Vec2f size, Vec2f lt, int gh, unsigned int color){
	Novice::DrawQuad(
		static_cast<int>((pos.x - (size.x/ 2))),
		static_cast<int>((pos.y - (size.y / 2))),
		static_cast<int>((pos.x + (size.x/ 2))),
		static_cast<int>((pos.y - (size.y / 2))),
		static_cast<int>((pos.x - (size.x/ 2))),
		static_cast<int>((pos.y + (size.y / 2))),
		static_cast<int>((pos.x + (size.x/ 2))),
		static_cast<int>((pos.y + (size.y / 2))),
		static_cast<int>(lt.x),
		static_cast<int>(lt.y),
		static_cast<int>(size.x),
		static_cast<int>(size.y),
		gh,
		color
	);

}

void DrawQuad(RectVerf vertex, Vec2f size, Vec2f lt, int gh, unsigned int color){
	Novice::DrawQuad(
		static_cast<int>(ceilf(vertex.lt.x)),
		static_cast<int>(ceilf(vertex.lt.y)),
		static_cast<int>(ceilf(vertex.rt.x)),
		static_cast<int>(ceilf(vertex.rt.y)),
		static_cast<int>(ceilf(vertex.lb.x)),
		static_cast<int>(ceilf(vertex.lb.y)),
		static_cast<int>(ceilf(vertex.rb.x)),
		static_cast<int>(ceilf(vertex.rb.y)),
		static_cast<int>(lt.x),
		static_cast<int>(lt.y),
		static_cast<int>(size.x),
		static_cast<int>(size.y),
		gh,
		color
	);
}


void PlayAudio(int& voiceHandle, int soundHandle, float soundVolume, bool isLoop) {
	if (Novice::IsPlayingAudio(voiceHandle) == 0 || voiceHandle == -1) {
		voiceHandle = Novice::PlayAudio(soundHandle, isLoop, soundVolume);
	}
}
