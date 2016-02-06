#include <SDL2/SDL.h>
#include <vector>
#include <string>
#include "mainclass.h"
#include "../files/button.h"

using namespace std;

void MainClass::createButtons() {
	vector <string> buttonTexts;
	buttonTexts.push_back("Resume game");
	buttonTexts.push_back("Options");
	buttonTexts.push_back("Quit game");
	buttonTexts.push_back("Play logo");
	vector < SDL_Color > colors;
	color.r = 100;
	color.g = 255;
	color.b = 100;
	colors.push_back(color);
	color.r = 100;
	color.g = 0;
	color.b = 255;
	colors.push_back(color);
	color.r = 255;
	color.g = 100;
	color.b = 100;
	colors.push_back(color);
	color.r = 255;
	color.g = 100;
	color.b = 255;
	colors.push_back(color);
	int size = buttonTexts.size();
	SDL_Texture* texture = NULL;
	color.r = 255;
	color.g = 255;
	color.b = 255;
	Button test(20,20,200,50,150,255,255, texture);
	for (int i = 0; i < size; i++) { // DUD PAUSE YA SHIT
		godofwar45.newText( string(buttonTexts[i]), 200, color, RENDERER);
		test.reset(40,60*i+40,400,50,colors[i].r,colors[i].g,colors[i].b, godofwar45.renderText(buttonTexts[i]));
		test.changeXState(1,50);
		test.changeXState(2,50);
		test.changeXState(3,50);
		test.changeRedState(1,colors[i].r-50);
		test.changeGreenState(1,colors[i].g-50);
		test.changeBlueState(1,colors[i].b-50);
		test.changeRedState(2,colors[i].r-100);
		test.changeGreenState(2,colors[i].g-100);
		test.changeBlueState(2,colors[i].b-100);
		test.changeXDelayState(0,70);
		test.changeColorDelayState(0,70);
		test.changeXDelayState(1,300);
		test.changeColorDelayState(1,300);
		test.changeColorDelayState(2,0);
		pauseButtons.push_back(test);
	}
	buttonTexts.clear();
	buttonTexts.push_back("Go back");
	buttonTexts.push_back("Graphics");
	buttonTexts.push_back("Controls");
	colors.clear();
	color.r = 255;
	color.g = 100;
	color.b = 150;
	colors.push_back(color);
	color.r = 100;
	color.g = 50;
	color.b = 255;
	colors.push_back(color);
	color.r = 100;
	color.g = 50;
	color.b = 255;
	colors.push_back(color);
	size = buttonTexts.size();
	color.r = 255;
	color.g = 255;
	color.b = 255;
	for (int i = 0; i < size; i++) { // DUD PAUSE YA SHIT
		godofwar45.newText( string(buttonTexts[i]), 200, color, RENDERER);
		test.reset(40,60*i+40,400,50,colors[i].r,colors[i].g,colors[i].b, godofwar45.renderText(buttonTexts[i]));
		test.changeXState(1,50);
		test.changeXState(2,50);
		test.changeXState(3,50);
		test.changeRedState(1,colors[i].r-50);
		test.changeGreenState(1,colors[i].g-50);
		test.changeBlueState(1,colors[i].b-50);
		test.changeRedState(2,colors[i].r-100);
		test.changeGreenState(2,colors[i].g-100);
		test.changeBlueState(2,colors[i].b-100);
		test.changeXDelayState(0,70);
		test.changeColorDelayState(0,70);
		test.changeXDelayState(1,300);
		test.changeColorDelayState(1,300);
		test.changeColorDelayState(2,0);
		optionsButtons.push_back(test);
	}
	buttonTexts.clear();
	buttonTexts.push_back("Go back");
	buttonTexts.push_back("Toggle fullscreen");
	buttonTexts.push_back("1600 x 900");
	buttonTexts.push_back("1500 x 800");
	buttonTexts.push_back("1000 x 800");
	buttonTexts.push_back("800 x 600");
	colors.clear();
	color.r = 255; color.g = 100; color.b = 150;
	colors.push_back(color);
	color.r = 150; color.g = 150; color.b = 150;
	colors.push_back(color);
	colors.push_back(color);
	colors.push_back(color);
	colors.push_back(color);
	colors.push_back(color);

	size = buttonTexts.size();
	color.r = 255;
	color.g = 255;
	color.b = 255;
	for (int i = 0; i < size; i++) {
		steelfish30.newText( string(buttonTexts[i]), 200, color, RENDERER);
		test.reset(40,45*i+40,200,35,colors[i].r,colors[i].g,colors[i].b, steelfish30.renderText(buttonTexts[i]));

		test.changeRedState(1,colors[i].r-50);
		test.changeGreenState(1,colors[i].g-50);
		test.changeBlueState(1,colors[i].b-50);

		test.changeRedState(2,colors[i].r-100);
		test.changeGreenState(2,colors[i].g-100);
		test.changeBlueState(2,colors[i].b-100);

		test.changeColorDelayState(0,70);
		test.changeColorDelayState(1,300);

		graphicsButtons.push_back(test);
	}
}