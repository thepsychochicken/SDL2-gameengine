#include <SDL2/SDL.h>
#include <vector>
#include "follow.h"
#include "mouse.h"
#include "button.h"

using namespace std;

void Button::changeXState(int state, int value) {
	xValues[state] = value;
}
void Button::changeYState(int state, int value) {
	yValues[state] = value;
}
void Button::changeWState(int state, int value) {
	wValues[state] = value;
}
void Button::changeHState(int state, int value) {
	hValues[state] = value;
}
void Button::changeRedState(int state, int value) {
	if (value > 255) {value = 255;}
	if (value < 0) {value = 0;}
	redValues[state] = value;
}
void Button::changeGreenState(int state, int value) {
	if (value > 255) {value = 255;}
	if (value < 0) {value = 0;}
	greenValues[state] = value;
}
void Button::changeBlueState(int state, int value) {
	if (value > 255) {value = 255;}
	if (value < 0) {value = 0;}
	blueValues[state] = value;
}
void Button::changeGeneralDelayState(int state, int value) {
	xDelay[state] = value;
	yDelay[state] = value;
	wDelay[state] = value;
	hDelay[state] = value;
	colorDelay[state] = value;
}
void Button::changeXDelayState(int state, int value) {
	xDelay[state] = value;
}
void Button::changeYDelayState(int state, int value) {
	yDelay[state] = value;
}
void Button::changeWDelayState(int state, int value) {
	wDelay[state] = value;
}
void Button::changeHDelayState(int state, int value) {
	hDelay[state] = value;
}
void Button::changeColorDelayState(int state, int value) {
	colorDelay[state] = value;
}

void Button::reset(int X, int Y, int W, int H,int RED, int GREEN, int BLUE, SDL_Texture* text) {
	x.reset(0, X, X);
	y.reset(0, Y, Y);
	w.reset(0, W, W);
	h.reset(0, H, H);
	red.reset(0, RED, RED);
	green.reset(0, GREEN, GREEN);
	blue.reset(0, BLUE, BLUE);
	xValues.clear();
	yValues.clear();
	wValues.clear();
	hValues.clear();
	redValues.clear();
	greenValues.clear();
	blueValues.clear();
	xDelay.clear();
	yDelay.clear();
	wDelay.clear();
	hDelay.clear();
	colorDelay.clear();
	for (int i = 0; i < 3; i++) {

		xValues.push_back(X);
		yValues.push_back(Y);
		wValues.push_back(W);
		hValues.push_back(H);
		redValues.push_back(RED);
		greenValues.push_back(GREEN);
		blueValues.push_back(BLUE);
		xDelay.push_back(0);
		yDelay.push_back(0);
		wDelay.push_back(0);
		hDelay.push_back(0);
		colorDelay.push_back(0);
	}
	buttonText = text;
	insideLastTime = false;
	mouseDownlastTime = false;
	lastState = 0;
}

Button::Button(int X, int Y, int W, int H,int RED, int GREEN, int BLUE, SDL_Texture* text ) {
	reset( X, Y, W, H, RED, GREEN, BLUE, text);
}

Button::~Button() {

}


int Button::check(Mouse *mouse) {
	int X = x.getPoint();
	int Y = y.getPoint();
	int W = w.getPoint();
	int H = h.getPoint();
	int RED = red.getPoint();
	int GREEN = green.getPoint();
	int BLUE = blue.getPoint();
	int state = 0;
	if (mouse->x > X && mouse->x < X+W && mouse->y > Y && mouse->y < Y+H) {
		if (!insideLastTime) {
			insideLastTime = true;
		}
		if (mouse->left) {
			state = 2; // Active
			mouseDownlastTime = true;
		}
		else if (mouseDownlastTime && !mouse->left) {
			state = 3; // Click (Release when still hover)
			mouseDownlastTime = false;
		}
		else {
			state = 1; // Hover
		}
	}
	else {
		if (insideLastTime) {
			mouseDownlastTime = false;
			insideLastTime = false;
		}
		state = 0;
	}
	if (state != lastState) {
		lastState = state;
		x.reset(xDelay[state],X,xValues[state]);
		y.reset(yDelay[state],Y,yValues[state]);
		w.reset(wDelay[state],W,wValues[state]);
		h.reset(hDelay[state],H,hValues[state]);
		red.reset(colorDelay[state],RED,redValues[state]);
		green.reset(colorDelay[state],GREEN,greenValues[state]);
		blue.reset(colorDelay[state],BLUE,blueValues[state]);
	}
	return state;
}


void Button::render(SDL_Renderer* &RENDERER) {
	int X = x.getPoint();
	int Y = y.getPoint();
	int W = w.getPoint();
	int H = h.getPoint();
	int TW,TH;
	SDL_QueryTexture( buttonText, NULL, NULL, &TW, &TH );
	SDL_Rect rect = {X,Y,W,H};
	SDL_SetRenderDrawColor(RENDERER, red.getPoint(), green.getPoint(), blue.getPoint(), 0xFF);
	SDL_RenderFillRect(RENDERER, &rect); // Lav firkant
	rect.x = (H/2)+X;
	rect.y = ((H-TH)/2)+Y;
	rect.w = TW;
	rect.h = TH;
	SDL_RenderCopy(RENDERER, buttonText, NULL, &rect); // Lav tekst
}