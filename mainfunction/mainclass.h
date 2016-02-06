#ifndef _MAINCLASS_
	#define _MAINCLASS_

	#include <SDL2/SDL.h>
	#include <iostream>
	#include <vector>
	#include <string>
	#include "../files/button.h"
	#include "../files/fontrenderer.h"
	#include "../files/functions.h"
	#include "../files/mouse.h"
	#include "../files/follow.h"

	using namespace std;

	class MainClass {
		private:
			int windowW,windowH;

			bool fullscreen;
			bool pause;

			string gameName;

			Mouse mouse;
			Follow boxX;
			Follow boxY;
			SDL_Window* window = NULL;
			SDL_Renderer* RENDERER = NULL;
			SDL_Texture* star;
			SDL_Event e;
			FontRenderer steelfish30;

			SDL_Rect rect;

			SDL_Color color;
			// Global changes to give to buttons

			FontRenderer godofwar45;

			vector <Button> pauseButtons;
			vector <Button> graphicsButtons;
			vector <Button> optionsButtons;

			vector < int > whatPauseMenu;

			vector <Particle> particles;

			// end of button

		public:
			bool running;
			string averageFPS;
			
			MainClass();
			void createButtons();
			void runGame();
			void handleMenu();
			void getEvents();
			void tick(int);
	};

#endif