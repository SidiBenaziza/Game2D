#pragma once

#include "SDL.h"
#include "ECS.h"
#include "TransformComponent.h"
#include "SpriteComponent.h"

class TileComponent : public Component
{
public:
	TransformComponent *transform_;
	SpriteComponent *sprite_;

	SDL_Rect tileRect_;
	int tileID;
	char* path_;

	TileComponent() = default;

	TileComponent(int x, int y, int w, int h, int id)
	{
		tileRect_.x = x;
		tileRect_.y = y;
		tileRect_.w = w;
		tileRect_.h = h;

		tileID = id;

		switch (tileID) {
		case 0:
			path_ = "assets/water.png";
			break;

		case 1:
			path_ = "assets/dirt.png";
			break;

		case 2:
			path_ = "assets/grass.png";
			break;


		default:
			break;
		}

	}

	void init() override
	{
		entity_->addComponent<TransformComponent>(static_cast<float>(tileRect_.x),static_cast<float>(tileRect_.y), tileRect_.w, tileRect_.h, 1);
		transform_ = &entity_->getComponent<TransformComponent>();

		entity_->addComponent<SpriteComponent>(path_);
		sprite_ = &entity_->getComponent<SpriteComponent>();


	}

};