#pragma once
#include <SafeDelete.h>
#include "BaseEntity.h"
#include "LoadJson.h"
#include "BulletManager.h"

#ifdef _DEBUG
#include "ImGuiManager.h"
#endif

class Player
	:public BaseEntity {

private:

	int GH_;

	float gravity_;

	// hp ----------------------------
	int hp_;
	
	// address ----------------------------
	VertexAddress address_;
	VertexAddress preAddress_;

	// bullet ------------------------------
	// normal
	int bulletCoolTime_;
	int coolTimeLimit_;

	// charge
	int chargeTime_;
	int chargeCoolTime_;

	// flag ------------------------------
	bool isInvincible_;
	bool isJump_;
	bool isChargeShot_;
	bool inBubble_;

	// count ------------------------------
	int invincibleCount_;

	BulletManager* bulletManager_;

	// life ------------------------------
	Vec2f lifePos_[5];
	int lifeGH_;

public:

	Player();
	~Player();

	void Init()override;
	void Update()override;
	void Draw()override;

	void Move();
	void Shot();
	void ScreenClamp();
	void AddressClamp();
	void Invincible();

	// acceser
	void SetWorldPos(Vec2f pos) { worldPos_ = pos; }
	void SetHp(const int& hp) { hp_ = hp; }
	void SetIsJump(const bool& isJump) { isJump_ = isJump; }
	void SetIsInvincible(const bool& isInvincible) { isInvincible_ = isInvincible; }
	void SetInBuble(const bool& inBubble) { inBubble_ = inBubble; }

	int GetHp() const { return hp_; }
	bool GetIsInvincible() const { return isInvincible_; }
	bool GetIsJump() const { return isJump_; }
	bool isChargeShot() const { return isChargeShot_; }
	bool GetInBubble() const { return inBubble_; }
	Vec2f GetWorldPos() const { return worldPos_; }
	Vec2f GetSize() const { return size_; }
	RectVerf GetWorldVertex() const { return worldVertex_; }
	VertexAddress GetAddress() const { return address_; }
	VertexAddress GetPreAddress() const { return preAddress_; }
	BulletManager* GetBulletManager()  { return bulletManager_; }

};