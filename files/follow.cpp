#include <SDL2/SDL.h>
#include <cmath>
#include "follow.h"

#define PI 3.14159265

Follow::Follow(int timeToTake,int p1,int p2) {
	startTime = SDL_GetTicks();
	timeT = timeToTake;
	startP = p1;
	endP = p2;
}

Follow::Follow() {
	startTime = SDL_GetTicks();
	timeT = 0;
	startP = 0;
	endP = 0;
}

void Follow::reset(int timeToTake,int p1,int p2) {
	startTime = SDL_GetTicks();
	timeT = timeToTake;
	startP = p1;
	endP = p2;

}

int Follow::getPoint() {
	int nowTime = SDL_GetTicks();
	int point;
	float percent = (double)(nowTime-startTime)/timeT;
	if (percent >= 1) {
		return endP;
	}
	point = (endP-startP)*percent+startP;
	return point;
}