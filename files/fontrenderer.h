#ifndef _FONTRENDERER_
	#define _FONTRENDERER_

	#include <SDL2/SDL.h>
	#include <SDL2/SDL_ttf.h>
	#include <vector>
	#include <string>

	using namespace std;
	

	class FontRenderer {
		private:
			TTF_Font* font = NULL;
			vector <string> texts;
			vector <SDL_Texture*> textures;
		public:
			FontRenderer( string, int );
			FontRenderer();
			void setFont( string, int );
			void newText( string, int, SDL_Color, SDL_Renderer* );
			void renderDynamicText( string, int, SDL_Color, SDL_Renderer*&, int, int );
			SDL_Texture* renderText( string );
	};


#endif