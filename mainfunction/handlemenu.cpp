#include <vector>
#include <string>
#include "mainclass.h"

using namespace std;

void MainClass::handleMenu() {
	// pause stuff
	int state;
	int size = pauseButtons.size();
	if (whatPauseMenu.size() == 0) {
		for (int i = 0; i < size; i++) {
			state = pauseButtons[i].check(&mouse);
			pauseButtons[i].render(RENDERER);
			if (state == 3) {
				switch(i) {
					case 0:
						pause = false;
						break;
					case 1:
						whatPauseMenu.push_back(i);
						// Options menu should be here
						break;
					case 2:
						running = false;
						cout << "Game should end now" << endl;
						break;
					case 3:
						playLogo(RENDERER,windowW,windowH);
						break;
				}
			}
			/*if (state > 0) {
				cout << buttonTexts[i] << " has state " << int(state) << endl;
			}*/
		}
	}
	else {
		switch(whatPauseMenu[0]) {
			case 1:
				if (whatPauseMenu.size() == 1) {
					size = optionsButtons.size();
					for (int i = 0; i < size; i++) {
						state = optionsButtons[i].check(&mouse);
						optionsButtons[i].render(RENDERER);
						if (state == 3) {
							switch(i) {
								case 0:
									whatPauseMenu.pop_back();
									break;
								case 1:
									whatPauseMenu.push_back(i);
									break;
							}
						}
					}
				}
				else {
					switch(whatPauseMenu[1]) {
						case 1:
							if (whatPauseMenu.size() == 2) {
								size = graphicsButtons.size();
								for (int i = 0; i < size; i++) {
									state = graphicsButtons[i].check(&mouse);
									graphicsButtons[i].render(RENDERER);
									if (state == 3) {
										switch(i) {
											case 0:
												whatPauseMenu.pop_back();
												break;
											case 1: // Toggle fullscreen
												changeInConfig("fullscreen", !fullscreen);
												break;
											case 2: // 1600 x 900
												changeInConfig("width", 1600);
												changeInConfig("height", 900);
												break;
											case 3: // 1500 x 800
												changeInConfig("width", 1500);
												changeInConfig("height", 800);
												break;
											case 4: // 1000 x 800
												changeInConfig("width", 1000);
												changeInConfig("height", 800);
												break;
											case 5: // 800 x 600
												changeInConfig("width", 800);
												changeInConfig("height", 600);
												break;
										}
										loadConfig( windowW, windowH, fullscreen );
										getWindow(window, RENDERER, windowW, windowH, fullscreen, gameName );
									}
								}
							}
							else {
								switch(whatPauseMenu[1]) {
								}
							}
							break;	
					}
				}
				break;
		}
	}
}
