#ifndef _FUNCTIONS_
	#define _FUNCTIONS_

	#include <iostream>
	#include <string>
	#include "particle.h"

	using namespace std;

	void loadConfig(int&, int&, bool&);

	void getWindow(SDL_Window*&, SDL_Renderer*&, int, int, bool, string );
	
	void renderTextFrame(SDL_Renderer*&, SDL_Texture*, int, int);

	void changeInConfig( string, int );
	void changeInConfig( string, bool );
	int loadConfigInt( string );

	string toString( int );

	SDL_Texture* loadTexture( SDL_Renderer*, string );

	void playLogo( SDL_Renderer*, int, int );
#endif