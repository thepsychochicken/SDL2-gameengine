#include "mainclass.h"
#include "fontrenderer.h"

using namespace std;

void MainClass::tick(int timePassedMS) {
	float timePassedS = (double)timePassedMS/1000;
	//std::cout << "Time passed in seconds: " << timePassedS << std::endl;  
	getEvents();
	SDL_SetRenderDrawColor( RENDERER, 0, 0, 0, 0 );
	SDL_RenderClear(RENDERER);
	if (!pause) {
			rect.x = boxX.getPoint()-40;
			rect.y = boxY.getPoint()-40;
			rect.w = 80;
			rect.h = 80;
			//cout << "boxX:" << boxX.getPoint();
			SDL_SetRenderDrawColor(RENDERER, 255, 255, 255, 255);
			SDL_RenderFillRect(RENDERER, &rect);
	}
	else {
		handleMenu();
		int size = particles.size();
		//std::cout << "you have " << size << " particles" << std::endl;
		for (int i = 0; i < size; i++) {
			particles[i].calc(timePassedS);
			particles[i].render();
			while (!particles[i].active) {
				particles.erase(particles.begin()+i);
				i++;
				size = particles.size();
			}
		}
	}
	if (keyboard.getKeyState("fpsKey")) {
		color.r = 255;
		color.g = 255;
		color.b = 255;
		steelfish30.renderDynamicText( averageFPS, 300, color, RENDERER, windowW-120, 20 );
	}
	SDL_RenderPresent( RENDERER );
}