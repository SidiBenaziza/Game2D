#pragma once

#include "SDL.h"

class Game
{
public:
	Game() = default;
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	

	bool running() const;

private:
	bool			isRunning_{ false };
	SDL_Window		*window_{ nullptr };
	SDL_Renderer	*renderer_{ nullptr };

	void clean();

};

