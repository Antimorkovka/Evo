#ifndef _TEXTURE_MANAGER
#define _TEXTURE_MANAGER
#include "SDL.h"
#include <map>

class TextureManager
{
public:
	static TextureManager* Instance()
	{
		if (instance == nullptr)
		{
			instance = new TextureManager();
			return instance;
		}
		return instance;
	}
	bool load(std::string texturePath, std::string id, SDL_Renderer *gRenderer);
	void draw(std::string id, int x, int y, int width, int height, SDL_Renderer *gRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawFrame(std::string id, int x, int y, int width, int height, int currentFrame, SDL_Renderer *gRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
private:
	TextureManager() {};
	static TextureManager* instance;
	std::map<std::string, SDL_Texture*> textureMap;
};
#endif