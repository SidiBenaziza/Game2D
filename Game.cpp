#include "Game.h"
#include "TextureManager.h"

#include "Map.h"
#include "ECS.h"
#include "Components.h"
#include "KeyboardController.h"
#include "Collision.h"

#include <iostream>


Map *map;

SDL_Renderer* Game::renderer_ = nullptr;

Manager manager;
SDL_Event Game::event;

std::vector<ColliderComponent*> Game::colliders_;

auto& player(manager.addEntity());
auto& wall(manager.addEntity());

auto& tile0(manager.addEntity());
auto& tile1(manager.addEntity());
auto& tile2(manager.addEntity());

Game::~Game()
{
	this->clean();
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (!SDL_Init(SDL_INIT_EVERYTHING))
	{
		std::cout << "SDL Initialiasted\n";

		window_ = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (window_)
		{
			std::cout << "Window Created!\n";
		}

		renderer_ = SDL_CreateRenderer(window_, -1, 0);

		if (renderer_)
		{
			SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255);

			std::cout << "Renderer Created!\n";
		}


		map = new Map();

		tile0.addComponent<TileComponent>(200,200,32,32,0);

		tile1.addComponent<TileComponent>(250,250,32,32,1);
		tile1.addComponent<ColliderComponent>("Dirt");

		tile2.addComponent<TileComponent>(150,150,32,32,2);
		tile2.addComponent<ColliderComponent>("Grass");

		player.addComponent<TransformComponent>(2);
		player.addComponent<SpriteComponent>("assets/player.png");
		player.addComponent<KeyboardController>();
		player.addComponent<ColliderComponent>("Player");

		wall.addComponent<TransformComponent>(300.0f, 400.0f, 200, 20, 1);

		wall.addComponent<SpriteComponent>("assets/dirt.png");
		wall.addComponent<ColliderComponent>("Wall");




		isRunning_ = true;

	}

	else
	{
		isRunning_ = false;
	}

}

void Game::handleEvents() {

	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning_ = false;
		break;

	default:
		break;
	}
}

void Game::update() {
	

	
	
	//
	destR.h = 64;
	destR.w = 64;

	destR.x = ++xPos;

}

void Game::render() {

	//clear the current rendering target with the drawing color.
	SDL_RenderClear(renderer_);


	SDL_RenderCopy(renderer_, playerTex, NULL, &destR);
	//update the screen with any rendering performed since the previous call.
	SDL_RenderPresent(renderer_);

}

void Game::clean() {

	SDL_DestroyRenderer(renderer_);
	SDL_DestroyWindow(window_);
	SDL_Quit();
}

bool Game::running() const {

	return isRunning_;

}


