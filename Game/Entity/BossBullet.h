#pragma once
#include "BaseEntity.h"
#include "LoadJson.h"

class BossBullet 
	:public BaseEntity{

private:

	float speed_;
	Vec2f bossPos_;
	Vec2f playerPos_;

	int GH_;

public:

	BossBullet(const Vec2f& bossPos, const Vec2f& playerPos);
	~BossBullet();

	void Init()override;
	void Update()override;
	void Draw()override;

	// accesser
	void SetIsAlive(const bool& isAlive) { isAlive_ = isAlive; }

	bool GetIsAlive() const { return isAlive_; }
	Vec2f GetSize() const { return size_; }
};