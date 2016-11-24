#include<SDL.h>
#include<SDL_image.h>
#include <vector>
#include "../Texture/Texture.h"
#include "GenerationLandScape\GenHeader.h"
#include <iostream>
const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;

const int hex_width = 192;
const int hex_height = 166;

int main(int argc, char **argv)
{
	SDL_Window* gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	SDL_Renderer* gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_Event e;
	bool running = 1;
	Texture *t1 = new Texture(gRenderer), *t2 = new Texture(gRenderer), *t3 = new Texture(gRenderer);
	t1->loadImage("hex_example/dg_grounds32_40.png", SDL_Color{ 0, 0, 0 });
	t2->loadImage("hex_example/dg_grounds32_73.png", SDL_Color{ 0, 0, 0 });
	t3->loadImage("hex_example/dg_grounds32_75.png", SDL_Color{ 0, 0, 0 });
	SDL_Rect src{ 0, 0, hex_width, hex_height };
	std::vector<std::vector<int>> map(SCREEN_WIDTH / 144, std::vector<int>(SCREEN_HEIGHT / 83, 0));
	for (int i = 0; i < map.size(); i++)
		for (int j = 0; j < map[0].size(); j++)
			map[i][j] = rand() % 3;
	int wpixel = 0, hpixel = 0;
	while (running)
	{
		if (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				running = false;
			}
		}
		SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0);
		/*SDL_RenderClear(gRenderer);*/
		for (int i = 0; i < map.size(); i++)
		{
			wpixel = i % 2 ? (hex_width / 4 * 3) : 0;

			for (int j = 0; j < map[0].size(); j++)
			{
				switch (map[i][j])
				{
					case 0:
						{
							t1->render(wpixel, hpixel, &src);
							break;
						}
					case 1:

						{
							t2->render(wpixel, hpixel, &src);
							break;
						}
					case 2:
						{
							t3->render(wpixel, hpixel, &src);
							break;
						}
				}
				wpixel += hex_width / 2 * 3;
			}
			hpixel += hex_height / 2;
		}




		SDL_RenderPresent(gRenderer);

	}















	t1->free();
	t2->free();
	t3->free();
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = nullptr;
	gRenderer = nullptr;
	IMG_Quit();
	SDL_Quit();
	return 0;
}