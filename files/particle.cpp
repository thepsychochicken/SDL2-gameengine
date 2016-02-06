#include "particle.h"

#define PI 3.1415

Particle::~Particle() {

}

Particle::Particle() {
	active = false;
	RENDERER = NULL;
	TEXTURE = NULL;
}

Particle::Particle( SDL_Texture* texture, SDL_Renderer* renderer, int startX, int startY, int SIZE, int RANGE ) {
	reset(texture, renderer, startX, startY, SIZE, RANGE);
}

void Particle::reset( SDL_Texture* texture, SDL_Renderer* renderer, int startX, int startY, int SIZE, int RANGE) {
	active = true;
	TEXTURE = texture;
	RENDERER = renderer;
	x = startX;
	y = startY;
	float travelDirectionRad = fmod(rand(),(PI*2));
	radians = travelDirectionRad;
	movY = sin(travelDirectionRad);
	movX = cos(travelDirectionRad);
	tickDistance = (rand()%int(RANGE*0.7))+int(RANGE*0.3);
	radiansMovement = (rand()%10-5);
	if (radiansMovement == 0) {
		radiansMovement-=1;
	}
	radiansMovement/=10;
	float size = (double)((rand()%10)+5)/5;
	width.reset(1000,int (SIZE*size),0);
	height.reset(1000,int (SIZE*size),0);
}

void Particle::calc(float timePassed) {
	if (active) {
		if (width.getPoint() == 0) {
			active = false;
		}
		x += movX*timePassed*tickDistance;
		y += movY*timePassed*tickDistance;
		radians += radiansMovement;
	}
}

void Particle::render() {
	if (active) {
		int W = width.getPoint();
		int H = height.getPoint();
		SDL_Rect rect = {int(x-(W*0.5)),int(y-(H*0.5)),W,H};
		SDL_Point point = {int(W*0.5),int(H*0.5)};
		SDL_RenderCopyEx( RENDERER, TEXTURE, NULL, &rect, radians, &point, SDL_FLIP_NONE );
		//SDL_RenderCopy(RENDERER, TEXTURE, NULL, &rect);
	}
}

