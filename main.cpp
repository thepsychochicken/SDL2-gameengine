#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include "mainfunction/mainclass.h"
#include "files/functions.h"

int main ( int argc, char* args[] ) {
	MainClass game;

	int t1,t2;
	// FPS Variables
	int frameCap = 0;
	float timePerFrame = 0;
	if (frameCap > 0) {
		timePerFrame = (double)1000/frameCap;
	}
	float timeAdder = 0;
	float timeAdderAdder = timePerFrame-int(timePerFrame);
	std::cout << timeAdderAdder << endl;
	int lastTimeFPSUpdate = SDL_GetTicks();
	int collectedTimeFPS = 0;
	int framesFPS = 0;
	float averageTimePerFrame;
	int delayTime = 0;
	int timePassed = 0;
	t1 = SDL_GetTicks();
	// end of FPS
	while (game.running) {
		t2 = t1;
		t1 = SDL_GetTicks();
		timePassed = t1-t2;
		if (frameCap > 0) {
			delayTime = timePerFrame-timePassed;
			timeAdder += timeAdderAdder;
			if (delayTime <= 0) {
				delayTime = 0;
			}
			else if (timeAdder > 1) {
				delayTime--;
				timeAdder--;
			}
			SDL_Delay(delayTime);
			t1 = SDL_GetTicks();
			timePassed = t1-t2;
		}
		framesFPS++;
		collectedTimeFPS += timePassed;
		if (lastTimeFPSUpdate <= t1) {
			averageTimePerFrame = (double)collectedTimeFPS/framesFPS;
			framesFPS = 0;
			collectedTimeFPS = 0;
			lastTimeFPSUpdate+=1000;
			game.averageFPS = "FPS: " + toString(int(1000/averageTimePerFrame));
		}
		game.tick(timePassed);
	}
	return 1;
}