#include "Game.h"
#include "SDL.h"
#undef main

int main(int agrc, const char* agrv[]){

	Game *game = nullptr;
	game = new Game();

	int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;

	game->init("Game test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, false);

	while (game->running())
	{
		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameTime < frameDelay)
		{
			SDL_Delay(frameDelay - frameTime);
		}

	}

	delete game;

	return 0;
}