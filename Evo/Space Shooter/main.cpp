#include<SDL.h>
#include<SDL_image.h>

#include <vector>
#include <algorithm>
#include "../Texture/Texture.h"

using namespace std;

int SCREEN_WIDTH = 640;
int SCREEN_HEIGHT = 480;
int shipdx = 4;
int shipdy = 4;
int bulletdx = 10;

static bool pred(const SDL_Point & p);

int main(int argc, char **argv)
{

	SDL_Window* gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	SDL_Renderer* gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	Texture* spaceship = new Texture(gRenderer);
	spaceship->loadImage("Space Shooter/Spaceship.png", SDL_Color{ 0xff, 0xff, 0xff, 1 });
	Texture* bullettexture = new Texture(gRenderer);
	bullettexture->loadImage("Space Shooter/Bullet.png", SDL_Color{ 0xff, 0xff, 0xff, 1 });
	vector<SDL_Point> vbullet(0);


	bool end = false;
	SDL_Event e;
	const Uint8* currentKeyboardState;
	int shipx = 0, shipy = 0;
	while (!end)
	{

		if (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				end = true;
			}

			currentKeyboardState = SDL_GetKeyboardState(0);
			if (currentKeyboardState[SDL_SCANCODE_UP] && shipy >= shipdy)
				shipy -= shipdy;
			if (currentKeyboardState[SDL_SCANCODE_DOWN] && shipy + shipdy + spaceship->getHeight() <= SCREEN_HEIGHT)
				shipy += shipdy;
			if (currentKeyboardState[SDL_SCANCODE_LEFT] && shipx >= shipdx)
				shipx -= shipdx;
			if (currentKeyboardState[SDL_SCANCODE_RIGHT] && shipx + shipdx + spaceship->getWidth() <= SCREEN_WIDTH)
				shipx += shipdx;
			if (currentKeyboardState[SDL_SCANCODE_SPACE])
				vbullet.push_back(SDL_Point{ shipx + spaceship->getWidth(),shipy + (spaceship->getHeight() / 2) });



		}






		vbullet.erase(remove_if(vbullet.begin(), vbullet.end(), pred), vbullet.end());

		for (int i = 0; i < vbullet.size(); ++i)
		{
			vbullet[i].x += bulletdx;
		}





		SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0);
		SDL_RenderClear(gRenderer);
		for (auto SDL_Point = vbullet.begin(); SDL_Point != vbullet.end(); ++SDL_Point)
		{
			bullettexture->render(SDL_Point->x, SDL_Point->y);
		}
		spaceship->render(shipx, shipy);
		SDL_RenderPresent(gRenderer);

	}







	spaceship->~Texture();
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = nullptr;
	gRenderer = nullptr;
	IMG_Quit();
	SDL_Quit();
	return 0;
}

static bool pred(const SDL_Point & p)
{
	if (p.x + bulletdx > SCREEN_WIDTH)
		return true;
	else
		return false;
}
