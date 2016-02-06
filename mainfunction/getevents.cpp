#include "mainclass.h"

void MainClass::getEvents() {
	while( SDL_PollEvent( &e )) {
		switch(e.type) {
			case SDL_QUIT:
				running = false;
				break;
			case SDL_MOUSEMOTION: {
				//cout << "X = " << e.motion.x << endl << "Y = " << e.motion.y << endl;
				mouse.x = e.motion.x;
				mouse.y = e.motion.y;


				if (!pause) {
					boxX.reset(200,boxX.getPoint(),mouse.x);
					boxY.reset(200,boxY.getPoint(),mouse.y);
				}
				else {
					Particle particle( blood, RENDERER, mouse.x, mouse.y, 5, 100 );
					particles.push_back(particle);
				}
			}
			break;
			case SDL_MOUSEBUTTONDOWN:
				switch(e.button.button) {
					case 1:
						mouse.left = true;
						break;
					case 3:
						mouse.right = true;
						break;
					default:
						cout << "Mouse key pressed: " << int(e.button.button) << endl;
				}
				break;
			case SDL_MOUSEBUTTONUP:
				switch(e.button.button) {
					case 1:
						mouse.left = false;
						break;
					case 3:
						mouse.right = false;
						break;
				}
				break;
			case SDL_KEYDOWN:
			case SDL_KEYUP:
			switch(e.key.keysym.sym) {
					case 27:
							if (e.type == SDL_KEYDOWN) {
								if (whatPauseMenu.size() == 0) {
									pause = !pause;
								}
								else {
									whatPauseMenu.pop_back();
								}
							}
	 					if (!pause) {
							boxX.reset(200,boxX.getPoint(),mouse.x);
							boxY.reset(200,boxY.getPoint(),mouse.y);
						}
						break;
					default:
						cout << "Key pressed was: " << e.key.keysym.sym << endl;
				}
				break;
			default: 
				cout << e.type << endl;
		}
	}
}