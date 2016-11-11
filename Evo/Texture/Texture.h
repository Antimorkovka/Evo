#include<SDL.h>
#include<string>

class Texture
{
public:
	Texture(SDL_Renderer* Renderer);
	~Texture();
	bool loadImage(std::string path, SDL_Color RGBMap);
	void free();
	void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
	/*SDL_Texture* getTexture();*/
	int getWidth() const;
	int getHeight() const;


private:
	SDL_Texture* texture;
	SDL_Renderer* renderer;
	int width;
	int height;

};

