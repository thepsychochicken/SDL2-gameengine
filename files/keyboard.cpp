#include <SDL2/SDL.h>
#include <vector>
#include <string>
#include "keyboard.h"
#include "button.h"

using namespace std;

Keyboard::Keyboard() {
	keyCats.push_back("Movement");

	keyDesc.push_back("going right.");
	keyNames.push_back("rightKey");
	keyStates.push_back(0);
	keyValues.push_back(SDLK_d);
	keyRelCat.push_back(0);
	keyToggle.push_back(false);

	keyDesc.push_back("going left.");
	keyNames.push_back("leftKey");
	keyStates.push_back(0);
	keyValues.push_back(SDLK_a);
	keyRelCat.push_back(0);
	keyToggle.push_back(false);

	keyDesc.push_back("crouching.");
	keyNames.push_back("crouchKey");
	keyStates.push_back(0);
	keyValues.push_back(SDLK_s);
	keyRelCat.push_back(0);
	keyToggle.push_back(false);

	keyDesc.push_back("jumping.");
	keyNames.push_back("jumpKey");
	keyStates.push_back(0);
	keyValues.push_back(SDLK_w);
	keyRelCat.push_back(0);
	keyToggle.push_back(false);

	keyCats.push_back("Game Info");

	keyDesc.push_back("showing FPS.");
	keyNames.push_back("fpsKey");
	keyStates.push_back(0);
	keyValues.push_back(SDLK_i);
	keyRelCat.push_back(1);
	keyToggle.push_back(true);

	selectedFieldToChange = -1;

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
	if (selectedFieldToChange == -1) {
		int size = keyValues.size();
		for (int i = 0; i < size; i++) {
			if (keyValues[i] == e.key.keysym.sym) {
				cout << "Line 69" << endl;
				if (keyToggle[i]) {
					cout << "Line 71" << endl;
					if (e.type == SDL_KEYDOWN) {
						if (keyStates[i] == 1 || keyStates[i] == 0) {
							keyStates[i] = 2;
						}
						else if (keyStates[i] == 2 || keyStates[i] == 3) {
							keyStates[i] = 1;
						}
					}
					else {
						if (keyStates[i] == 1) {
							keyStates[i] = 0;
						}
						else if (keyStates[i] == 2) {
							keyStates[i] = 3;
						}
					}
				}
				else {
					cout << "Line 90" << endl;
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
	}
	else {
		keyValues[selectedFieldToChange] = e.key.keysym.sym;
		changeInConfig(keyNames[selectedFieldToChange], keyValues[selectedFieldToChange]);
		selectedFieldToChange = -1;
		createButtons( loadConfigInt( "width" ) );
	}
}

void Keyboard::setFont(FontRenderer* FONT) {
	font = FONT;
}

void Keyboard::setRenderer(SDL_Renderer* renderer) {
	RENDERER = renderer;
}

void Keyboard::addKey( string keyName, int keyValue ) {
	keyValues.push_back(keyValue);
	keyStates.push_back(false);
	keyNames.push_back(keyName);
}

bool Keyboard::getKeyState( string keyName) {
	int size = keyNames.size();
	for (int i = 0; i < size; i++) {
		if (keyName == keyNames[i]) {
			if (keyToggle[i] == true) {
				if (keyStates[i] <= 1) {
					return false;
				}
				else {
					return true;
				}
			}
			else {
				if (keyStates[i] > 0) {
					return true;
				}
				else {
					return false;
				}
			}
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

void Keyboard::createButtons(int screenWidth) {
	descriptionBoxes.clear();
	buttons.clear();
	int catsSize = keyCats.size();
	int keysSize = keyNames.size();
	string buttonText;

	int descWidth,buttonWidth,descX,buttonX;
	descWidth = ((screenWidth*0.9)*0.7)-5;
	buttonWidth = ((screenWidth*0.9)*0.3);
	descX = screenWidth*0.05;
	buttonX = screenWidth*0.05+(descWidth+5);

	SDL_Color color = {255,255,255,255};

	int y = 40;
	font->newText(string("test"),800,color,RENDERER);
	Button button(0,0,0,0,0,0,0,font->renderText(string("test")));
	for (int i = 0; i < catsSize; i++) {
		buttonText.assign(keyCats[i]);
		font->newText(buttonText,800,color,RENDERER);
		button.reset(descX,y,screenWidth*0.9,50,0,0,150,font->renderText(buttonText));
		descriptionBoxes.push_back(button);
		y+=60;
		for (int j = 0; j < keysSize; j++) {
			if (keyRelCat[j] == i) {

				buttonText.assign(keyDesc[j]);
				buttonText = "Key for " + buttonText;
				font->newText(buttonText,800,color,RENDERER);
				button.reset(descX,y,descWidth,40,100,100,100,font->renderText(buttonText));
				descriptionBoxes.push_back(button);

				buttonText.assign(SDL_GetKeyName(keyValues[j]));
				if (j == selectedFieldToChange) {
					buttonText = "Waiting for input";
				}
				font->newText(buttonText,800,color,RENDERER);
				button.reset(buttonX,y,buttonWidth,40,150,150,150,font->renderText(buttonText));
				button.changeRedState(1,100);
				button.changeRedState(2,50);
				button.changeRedState(3,50);
				button.changeColorDelayState(0,400);
				buttons.push_back(button);
				//cout << "Key name for '" << keyNames[j] << "' = " << buttonText << endl;
				y+=50;
			}
		}
	}
}

void Keyboard::checkButtons(Mouse* mouse) {
	int size = buttons.size();
	int buttonState;
	for (int i = 0; i < size; i++) {
		buttonState = buttons[i].check(mouse);
		if (buttonState == 3) {
			selectedFieldToChange = i;
			createButtons(loadConfigInt("width"));
		}
	}
}

void Keyboard::renderButtons() {
	int size = buttons.size();
	for (int i = 0; i < size; i++) {
		buttons[i].render(RENDERER);
	}
	size = descriptionBoxes.size();
	for (int i = 0; i < size; i++) {
		descriptionBoxes[i].render(RENDERER);
	}
}