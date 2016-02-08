#ifndef _KEYBOARD_
	#define _KEYBOARD_
	
	#include <SDL2/SDL.h>
	#include <vector>
	#include <iostream>
	#include <string>
	#include "button.h"
	#include "functions.h"
	#include "fontrenderer.h"
	#include "mouse.h"

	using namespace std;	

	class Keyboard {
		private:
			vector < Uint8 >  keyStates;
			vector < int >    keyValues;
			vector < string > keyNames;
			vector < string > keyDesc;
			vector < int >    keyRelCat;
			vector < string > keyCats;
			vector < bool >   keyToggle;
			vector < Button > buttons;

			vector < Button > descriptionBoxes;  // Render only

			int selectedFieldToChange; // Default on -1

			FontRenderer* font;
			SDL_Renderer* RENDERER = NULL;
		public:
			Keyboard();
			void checkEvent(SDL_Event);
			void addKey( string, int );
			void setFont( FontRenderer* );
			void setRenderer( SDL_Renderer* );
			bool getKeyState( string );
			bool getKeyState( int );
			void createButtons( int );
			void checkButtons( Mouse* );
			void renderButtons();
	};
	
#endif