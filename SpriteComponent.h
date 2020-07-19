#pragma once

#include "Components.h"
#include "TransformComponent.h"
#include "SDL.h"

class SpriteComponent : public Component {


private:

	TransformComponent *transform_;
	SDL_Texture *texture_;
	SDL_Rect srcRect_, destRect_;

public:
	SpriteComponent() = default;
	SpriteComponent(const char* path)
	{
		texture_ = TextureManager::LoadTexture(path);
	}

	void setTex(const char* path) {

		texture_ = TextureManager::LoadTexture(path);
	}
	void init() override {

		transform_ = &entity_->getComponent<TransformComponent>();

		srcRect_.x = srcRect_.y = 0;
		srcRect_.w = srcRect_.h = 32;
		destRect_.w = destRect_.h = 64;

	}

	void update() override {

		
		destRect_.x = (int)transform_->position.x_;
		destRect_.y = (int)transform_->position.y_;

	}

	void draw() override {

		TextureManager::Draw(texture_, srcRect_, destRect_);
	}
};