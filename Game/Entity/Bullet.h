#pragma once
#include "LoadJson.h"
#include "BaseEntity.h"

enum kBulletType {
	Bullet_Normal,
	Bullet_Charge
};

class Bullet
	:public BaseEntity{
private:

	int GH_;

	float speed_;
	Vec2f playerPos_;
	int chargeCount_;

	bool isAddressOver_;

	kBulletType type_;
	int hp_;

	int lifeTime_;
	int lifeTimeLimit_;

	VertexAddress address_;
	VertexAddress preAddress_;

public:

	Bullet(const Vec2f& pos, const int& count);
	~Bullet();

	void Init()override;
	void Update()override;
	void Draw()override;

	void AddressClamp();
	void ScreenOut();
	void GroundCollision();
	void LifeTime();

	// accesser
	void SetIsAlive(bool isAlive) { isAlive_ = isAlive; }
	void SetVelocity(const Vec2f& velocity) { velocity_ = velocity; }
	void SetHp(const int& hp) { hp_ = hp; }

	int GetHp() const { return hp_; }
	bool GetIsAlive() const { return isAlive_; }
	bool GetIsAddressOver() const { return isAddressOver_; }
	Vec2f GetWorldPos() const { return worldPos_; }
	Vec2f GetSize() const { return size_; }
	Vec2f GetVelocity() const { return velocity_; }

	kBulletType GetBulletType() const { return type_; }
	VertexAddress GetAddress() const { return address_; }
};