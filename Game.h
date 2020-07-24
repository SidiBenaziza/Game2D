#pragma once

#include "SDL.h"
#include "SDL_image.h"

#include <iostream>
#include <vector>
#define FPS 60

class ColliderComponent;

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
	static SDL_Renderer* renderer_;
	static SDL_Event event;
	static std::vector<ColliderComponent*> colliders_;

private:
//boolean for game running 
	bool			isRunning_{ false };
	SDL_Window		*window_{ nullptr };
          
	void clean();

};

