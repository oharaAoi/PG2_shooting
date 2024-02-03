#pragma once
#include "BaseEntity.h"
#include "LoadJson.h"
#include "BossBulletManager.h"

class Boss
:public BaseEntity{

private:

	Vec2f initPos_;

	bool isAlive_;
	bool isAppearance_;

	

	// count -----------------------
	int shotCount_;
	int shotCountLimit_;

	// time ------------------------
	int bulletCoolTime_;
	int bulletCoolTimeLimit_;

	int bulletShotCoolTime_;
	int bulletShotCoolTimeLimit;

	static int hp_;

	int GH_;

	EaseParam appearance_;

	BossBulletManager* bulletManager_;
	
public:

	Boss();
	~Boss();

	void Init();
	void Update();
	void Draw();

	// user method
	void Appearance();
	void Shot();
	void ShotTargetUpdate(const Vec2f& playerPos);

	// accesser
	static void SetHp(const int& hp) { hp_ = hp; }
	void SetIsAlive(const bool& isAlive) { isAlive_ = isAlive; }
	void SetIsAppearance(const bool& isAppearance) { isAppearance_ = isAppearance; }

	static int GetHp() { return hp_; }
	bool GetIsAlive() const { return isAlive_;}
	bool GetIsAppearance() const { return isAppearance_; }
	Vec2f GetWorldPos() const { return worldPos_; }
	Vec2f GetSize() const { return size_; }

	BossBulletManager* GetBulletManager() { return bulletManager_; }
};