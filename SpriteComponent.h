#pragma once

#include "Components.h"
#include "SDL.h"

class SpriteComponent : public Component {


private:

	positionComponent *position_;
	SDL_Texture *texture_;
	SDL_Rect srcRect_, destRect_;

public:
	SpriteComponent() = default;
	SpriteComponent(const char* path)
	{
		texture_ = TextureManager::LoadTexture(path);
	}

	void init() override {

		position_ = &entity_->getComponent<positionComponent>();

		srcRect_.x = srcRect_.y = 0;
		srcRect_.w = srcRect_.h = 32;
		destRect_.w = destRect_.h = 64;

	}

	void update() override {

		destRect_.x = position_->x();
		destRect_.y = position_->y();

	}

	void draw() override {

		TextureManager::Draw(texture_, srcRect_, destRect_);
	}
};