#pragma once

#include "SDL.h"
#include "SDL_image.h"

#include <iostream>

#define FPS 60



class Game
{
public:
	Game() = default;
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	
/*return true if game is running 
*/
	bool running() const;

private:
//boolean for game running 
	bool			isRunning_{ false };
	SDL_Window		*window_{ nullptr };
	SDL_Renderer	*renderer_{ nullptr };
          
	void clean();

};

