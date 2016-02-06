#include <SDL2/SDL.h>
#include <vector>
#include <string>
#include "keyboard.h"
#include "button.h"

using namespace std;

Keyboard::Keyboard() {

}

void Keyboard::CheckEvent(SDL_Event e) {
	int size = keyValues.size();
	for (int i = 0; i < size; i++) {
		if (keyValues[i] == e.key.keysym.sym) {
			if (e.type == SDL_KEYDOWN) {
				keyStates[i] = true;
			}
			else if (e.type == SDL_KEYUP) {
				keyStates[i] = false;
			}
		}
	}
}

void Keyboard::addKey( string keyName, int keyValue ) {
	keyValues.push_back(keyValue);
	keyStates.push_back(false);
	keyNames.push_back(keyName);
}

bool Keyboard::getKeyState( string buttonName) {
	int size = keyValues.size();
	for (int i = 0; i < size; i++) {
		if (buttonName == keyNames[i]) {
			return keyStates[i];
		}
	}
	return false;
}

bool Keyboard::getKeyState( int buttonID) {
	int size = keyValues.size();
	for (int i = 0; i < size; i++) {
		if (buttonID == keyValues[i]) {
			return keyStates[i];
		}
	}
	return false;
}

void Keyboard::checkButtons() {

}

void Keyboard::renderButtons() {
	int size = buttons.size();
	for (int i = 0; i < size; i++) {
		
	}
}