#include <SDL2/SDL.h>
#include <vector>
#include <string>
#include "keyboard.h"
#include "button.h"

using namespace std;

Keyboard::Keyboard() {

	keyDesc.push_back("going right.");
	keyNames.push_back("rightKey");
	keyStates.push_back(0);
	keyValues.push_back(SDLK_d);

	keyDesc.push_back("going left.");
	keyNames.push_back("leftKey");
	keyStates.push_back(0);
	keyValues.push_back(SDLK_a);

	keyDesc.push_back("crouching.");
	keyNames.push_back("crouchKey");
	keyStates.push_back(0);
	keyValues.push_back(SDLK_s);

	keyDesc.push_back("jumping.");
	keyNames.push_back("jumpKey");
	keyStates.push_back(0);
	keyValues.push_back(SDLK_w);
	int keyValue;
	int size = keyStates.size();
	for (int i = 0; i < size; i++) {
		keyValue = loadConfigInt(keyNames[i]);
		if (keyValue == -1) {
			changeInConfig(keyNames[i], keyValues[i]);
		}
		else if (keyValue >= 0) {
			keyValues[i] = keyValue;
		}
	}
}

void Keyboard::checkEvent(SDL_Event e) {
	int size = keyValues.size();
	for (int i = 0; i < size; i++) {
		if (keyValues[i] == e.key.keysym.sym) {
			if (e.type == SDL_KEYDOWN && keyStates[i] == 0) {
				keyStates[i] = 1;
				cout << "Congratz.. You pressed the '" << keyNames[i] << "'" << endl;
			}
			if (e.type == SDL_KEYDOWN && keyStates[i] == 1) {
				keyStates[i] = 2;
			}
			else if (e.type == SDL_KEYUP) {
				keyStates[i] = 0;
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