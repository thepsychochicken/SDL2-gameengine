#include <iostream>
#include <string>
#include "mainclass.h"
#include "particle.h"

using namespace std;

MainClass::MainClass() {
	windowW = 1400;
	windowH = 800;

	fullscreen = false;
	pause = true;
	running = true;

	averageFPS = "";

	gameName = "Cliff's Game engine";

	loadConfig(windowW,windowH,fullscreen);

	getWindow(window, RENDERER, windowW, windowH, fullscreen, gameName );

	playLogo(RENDERER, windowW, windowH);

	star = loadTexture(RENDERER, "images/particles/star.png");
	blood = loadTexture(RENDERER, "images/particles/blood.png");
	SDL_SetTextureBlendMode(star, SDL_BLENDMODE_ADD );

	steelfish30.setFont("fonts/steelfish_rg.ttf", 25);
	godofwar45.setFont("fonts/steelfish_rg.ttf", 40);
	
	color.r = 255;
	color.g = 255;
	color.b = 255;
	color.a = 255;

	rect.x = 0;
	rect.y = 0;
	rect.w = 0;
	rect.h = 0;

	createButtons();
}