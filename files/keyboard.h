#ifndef _KEYBOARD_
	#define _KEYBOARD_
	
	#include <SDL2/SDL.h>
	#include <vector>
	#include <string>
	#include "button.h"

	using namespace std;	

	class Keyboard {
		private:
			vector < bool > keyStates;
			vector < int > keyValues;
			vector < string > keyNames;
			vector < Button > buttons;
		public:
			Keyboard();
			void CheckEvent(SDL_Event);
			void addKey( string, int );
			bool getKeyState( string );
			bool getKeyState( int );
			void checkButtons();
			void renderButtons();
	};
	
#endif