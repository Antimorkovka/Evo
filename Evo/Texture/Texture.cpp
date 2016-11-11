#include"Texture.h"
#include <SDL.h>
#include <SDL_image.h>

Texture::Texture(SDL_Renderer* newRenderer)
{
	renderer = newRenderer;
	texture = nullptr;
	width = height = 0;
}

Texture::~Texture()
{
	free();
}

bool Texture::loadImage(std::string path, SDL_Color RGBMap)
{
	free();
	SDL_Texture* newTexture = nullptr;
	SDL_Surface* surface = IMG_Load(path.c_str());
	if (surface == nullptr)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, RGBMap.r, RGBMap.g, RGBMap.b));

		newTexture = SDL_CreateTextureFromSurface(renderer, surface);
		if (newTexture == nullptr)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			width = surface->w;
			height = surface->h;
		}
		SDL_FreeSurface(surface);
	}
	texture = newTexture;
	return texture != nullptr;
}

void Texture::free()
{
	if (texture != nullptr)
		SDL_DestroyTexture(texture);
	texture = nullptr;
	width = height = 0;
}

void Texture::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	SDL_Rect renderRect = { x,y,width,height };

	if (clip != nullptr)
	{
		renderRect.w = clip->w;
		renderRect.h = clip->h;
	}
	SDL_RenderCopyEx(renderer, texture, clip, &renderRect, angle, center, flip);
}

/*SDL_Texture* Texture::getTexture()
{
return texture;
}*/

int Texture::getWidth() const
{
	return width;
}

int Texture::getHeight() const
{
	return height;
}
