#ifndef _BUTTON_
	#define _BUTTON_
	
	#include <SDL2/SDL.h>
	#include <vector>
	#include "mouse.h"
	#include "follow.h"

	using namespace std;

	class Button {
		public:
			Button(int, int, int, int, int, int, int, SDL_Texture*);
			~Button();
			void reset(int, int, int, int, int, int, int, SDL_Texture*);
			void changeXState(int, int);
			void changeYState(int, int);
			void changeWState(int, int);
			void changeHState(int, int);
			void changeRedState(int, int);
			void changeGreenState(int, int);
			void changeBlueState(int, int);
			void changeXDelayState(int, int);
			void changeYDelayState(int, int);
			void changeWDelayState(int, int);
			void changeHDelayState(int, int);
			void changeColorDelayState(int, int);
			void changeGeneralDelayState(int, int);
			int check(Mouse *mouse);
			void render(SDL_Renderer* &RENDERER);
		private: 
			Follow x, y, w, h, red, green, blue;
			vector <int> xValues, yValues, wValues, hValues, redValues, greenValues, blueValues;
			vector <int> xDelay, yDelay, wDelay, hDelay, colorDelay;
			bool insideLastTime,mouseDownlastTime;
			int lastState;
			SDL_Texture* buttonText = NULL;
	};

#endif