#include "TextureManager.h"
#include "SDL_image.h"

bool TextureManager::load(std::string texturePath, std::string id, SDL_Renderer* gRenderer)
{
	SDL_Surface *tempSurface = IMG_Load(texturePath.c_str());
	if (tempSurface == 0)
	{
		return false;
	}
	SDL_Texture *loadedTexture = SDL_CreateTextureFromSurface(gRenderer, tempSurface);
	SDL_FreeSurface(tempSurface);
	if (loadedTexture != 0)
	{
		textureMap[id] = loadedTexture;
		return true;
	}
	return false;
}

void TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer* gRenderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = srcRect.y = 0;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;
	SDL_RenderCopyEx(gRenderer, textureMap[id], &srcRect, &destRect, 0, 0, flip);

}

void TextureManager::drawFrame(std::string id, int x, int y, int width, int height, int currentFrame, SDL_Renderer* gRenderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = width*currentFrame;
	srcRect.y = 0;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;
	SDL_RenderCopyEx(gRenderer, textureMap[id], &srcRect, &destRect, 0, 0, flip);
}
