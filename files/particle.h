#ifndef _PARTICLES_
	#define _PARTICLES_

	#include <SDL2/SDL.h>
	#include <ctime>
	#include <cmath>
	#include <iostream>
	#include <stdlib.h>
	#include "follow.h"

	class Particle {
		private:
			SDL_Renderer* RENDERER;
			SDL_Texture* TEXTURE;
			float x,y;
			float movX,movY;
			float tickDistance;
			float radians,radiansMovement;
			Follow width,height;
		public:
			bool active;
			~Particle();
			Particle();
			Particle( SDL_Texture* , SDL_Renderer* , int , int, int, int );
			void reset( SDL_Texture* , SDL_Renderer* , int , int, int, int );
			void calc( float );
			void render();
	};

#endif