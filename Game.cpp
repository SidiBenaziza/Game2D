#include "Game.h"
#include <iostream>

int xPos = 0;
SDL_Texture* playerTex;
SDL_Rect destR;


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


		auto tmpSurface = IMG_Load("assets/player.png");
		playerTex = SDL_CreateTextureFromSurface(renderer_, tmpSurface);
		SDL_FreeSurface(tmpSurface);

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


