#include "player.h"
#include "Boss.h"	

class BossCollision {
private:

	float length_;

	Player* player_;
	Boss* boss_;
	BulletManager* bulletManager_;

public:

	BossCollision(Player* player, Boss* boss);
	~BossCollision();

	void Init(Player* player, Boss* boss);
	void Update();

	void BullletCollision();
};