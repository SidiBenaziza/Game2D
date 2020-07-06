#include "Game.h"
#include "SDL.h"
#undef main

int main(int agrc, const char* agrv[]){

	Game *game = nullptr;
	game = new Game();

	game->init("Game test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, false);

	while (game->running())
	{
		game->handleEvents();
		game->update();
		game->render();

	}

	delete game;

	return 0;
}