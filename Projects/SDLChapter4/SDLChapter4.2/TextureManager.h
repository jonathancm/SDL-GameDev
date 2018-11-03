#ifndef __TEXTUREMANAGER__
#define __TEXTUREMANAGER__

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <stdlib.h>
#include <map>

class TextureManager
{
public:
	static TextureManager* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new TextureManager();
			return s_pInstance;
		}

		return s_pInstance;
	}

	bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);

	/* ------------- draw ------------- 
	 * x,y: position of image on user display
	 * width,height: size of square to pick from source image
	 * --------------------------------*/
	void draw(std::string id, int x, int y,
		int width, int height,
		SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	/* ------------- drawFrame -------------
	 * x,y: position of image on user display
	 * width,height: size of square to pick from source image
	 * currentFrame,currentRow: allows to select pictures from animation strips
	 * --------------------------------*/
	void drawFrame(std::string id, int x, int y,
		int width, int height,
		int currentRow, int currentFrame,
		SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
	TextureManager(){}
	~TextureManager(){}

	/* Map to Texture objects */
	std::map<std::string, SDL_Texture*> m_textureMap;
	static TextureManager* s_pInstance;
};

typedef TextureManager TheTextureManager;

#endif //define(__TEXTUREMANAGER__)