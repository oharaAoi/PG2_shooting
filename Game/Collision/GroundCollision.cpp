#include "GroundCollision.h"

GroundCollision::GroundCollision(Player* player, Ground* ground){
	Init(player,ground);
}

GroundCollision::~GroundCollision(){
}

void GroundCollision::Init(Player* player, Ground* ground){
	player_ = player;
	ground_ = ground;

	bulletManager_ = player_->GetBulletManager();
}

void GroundCollision::Update(){
	PlayerGroundCollision();
	BulletGroundCollision();
}

void GroundCollision::PlayerGroundCollision(){
	if (player_->GetAddress().lb.row >= 2 || player_->GetAddress().lt.row >= 2) {
		return;
	}

	// leftTop
	if (MapChip::GetMapChipArr()[player_->GetAddress().lt.row][player_->GetAddress().lt.col] != NONE) {
		playerPos_ = player_->GetWorldPos();
		playerVertex_ = player_->GetWorldVertex().lt;
		blocksPos_ = ground_->GetPos(player_->GetAddress().lt.row, player_->GetAddress().lt.col);

		if (MapChip::GetMapChipArr()[player_->GetPreAddress().lt.row][player_->GetAddress().lt.col] != NONE) {
			distance_ = { 0,0 };
			distance_.x = (blocksPos_.x + player_->GetSize().x / 2) - playerVertex_.x;

			playerPos_.x += distance_.x;

			player_->SetWorldPos(playerPos_);

			player_->MakeScreenMatrix();
		}

		if (MapChip::GetMapChipArr()[player_->GetAddress().lt.row][player_->GetPreAddress().lt.col] != NONE) {
			distance_ = { 0,0 };
			distance_.y = (blocksPos_.y - player_->GetSize().y / 2) - playerVertex_.y;

			playerPos_.y += distance_.y;

			player_->SetWorldPos(playerPos_);

			player_->MakeScreenMatrix();
		}
	}

	// rightTop
	if (MapChip::GetMapChipArr()[player_->GetAddress().rt.row][player_->GetAddress().rt.col] != NONE) {
		playerPos_ = player_->GetWorldPos();
		playerVertex_ = player_->GetWorldVertex().rt;
		blocksPos_ = ground_->GetPos(player_->GetAddress().rt.row, player_->GetAddress().rt.col);

		if (MapChip::GetMapChipArr()[player_->GetPreAddress().rt.row][player_->GetAddress().rt.col] != NONE) {
			distance_ = { 0,0 };
			distance_.x = (blocksPos_.x - player_->GetSize().x / 2) - playerVertex_.x;

			playerPos_.x += distance_.x;

			player_->SetWorldPos(playerPos_);

			player_->MakeScreenMatrix();
		}

		if (MapChip::GetMapChipArr()[player_->GetAddress().rt.row][player_->GetPreAddress().rt.col] != NONE) {
			distance_ = { 0,0 };
			distance_.y = (blocksPos_.y - player_->GetSize().y / 2) - playerVertex_.y;

			playerPos_.y += distance_.y;

			player_->SetWorldPos(playerPos_);

			player_->MakeScreenMatrix();
		}
	}

	// leftBottom
	if (MapChip::GetMapChipArr()[player_->GetAddress().lb.row][player_->GetAddress().lb.col] != NONE) {
		playerPos_ = player_->GetWorldPos();
		playerVertex_ = player_->GetWorldVertex().lb;
		blocksPos_ = ground_->GetPos(player_->GetAddress().lb.row, player_->GetAddress().lb.col);

		if (MapChip::GetMapChipArr()[player_->GetPreAddress().lb.row][player_->GetAddress().lb.col] != NONE) {
			distance_ = { 0,0 };
			distance_.x = (blocksPos_.x + player_->GetSize().x / 2) - playerVertex_.x;

			playerPos_.x += distance_.x;

			player_->SetWorldPos(playerPos_);
			player_->SetIsJump(false);

			player_->MakeScreenMatrix();

		}

		if (MapChip::GetMapChipArr()[player_->GetAddress().lb.row][player_->GetPreAddress().lb.col] != NONE) {
			distance_ = { 0,0 };
			distance_.y = (blocksPos_.y + player_->GetSize().y / 2) - playerVertex_.y;

			playerPos_.y += distance_.y;

			player_->SetWorldPos(playerPos_);
			player_->SetIsJump(false);

			player_->MakeScreenMatrix();

		}
	}

	// rightBottom
	if (MapChip::GetMapChipArr()[player_->GetAddress().rb.row][player_->GetAddress().rb.col] != NONE) {
		playerPos_ = player_->GetWorldPos();
		playerVertex_ = player_->GetWorldVertex().rb;
		blocksPos_ = ground_->GetPos(player_->GetAddress().rb.row, player_->GetAddress().rb.col);

		if (MapChip::GetMapChipArr()[player_->GetPreAddress().rb.row][player_->GetAddress().rb.col] != NONE) {
			distance_ = { 0,0 };
			distance_.x = (blocksPos_.x - player_->GetSize().x / 2) - playerVertex_.x;

			playerPos_.x += distance_.x;

			player_->SetWorldPos(playerPos_);

			player_->MakeScreenMatrix();

		}

		if (MapChip::GetMapChipArr()[player_->GetAddress().rb.row][player_->GetPreAddress().rb.col] != NONE) {
			distance_ = { 0,0 };
			distance_.y = (blocksPos_.y + player_->GetSize().y / 2) - playerVertex_.y;

			playerPos_.y += distance_.y;

			player_->SetWorldPos(playerPos_);

			player_->MakeScreenMatrix();

		}
	}
}

void GroundCollision::BulletGroundCollision(){
	auto bulletsList = bulletManager_->GetBulletList();
	for (auto bullets = bulletsList->begin(); bullets != bulletsList->end(); ++bullets) {
		if (!bullets->GetIsAddressOver()) {
			if (MapChip::GetMapChipArr()[bullets->GetAddress().lb.row][bullets->GetAddress().lb.col] != NONE) {
				bullets->GroundCollision();
			}
		}
	}
}
 