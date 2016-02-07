#ifndef _KEYBOARD_
	#define _KEYBOARD_
	
	#include <SDL2/SDL.h>
	#include <vector>
	#include <string>
	#include "button.h"
	#include "functions.h"

	using namespace std;	

	class Keyboard {
		private:
			vector < Uint8 > keyStates;
			vector < int > keyValues;
			vector < string > keyNames;
			vector < string > keyDesc;
			vector < Button > buttons;
		public:
			Keyboard();
			void checkEvent(SDL_Event);
			void addKey( string, int );
			bool getKeyState( string );
			bool getKeyState( int );
			void checkButtons();
			void renderButtons();
	};
	
#endif