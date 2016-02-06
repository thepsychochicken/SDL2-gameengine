#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "functions.h"
#include "follow.h"
#include <SDL2/SDL_image.h>

using namespace std;

void loadConfig(int &wW, int &wH, bool &fullscreen) {
	ifstream file ("config.txt");
	//fscanf(file, "%s = %s", name, value);
	string line;
	if (file.is_open()) {
		string name, value;
		int splitPos;
		while (getline(file,line)) {
			if (line.length() > 3) {
				if (line.substr(0,2) != "//") {
					splitPos = line.find(": ");
					name = line.substr(0,splitPos);
					value = line.substr(splitPos+2);
					cout << "Name of variable: " << name << " = " << value << endl;
					if (name == "height") {
						wH = atoi (value.c_str());
					}
					else if (name == "width") {
						wW = atoi (value.c_str());
					}
					else if (name == "fullscreen") {
						if (value == "true") {
							fullscreen = true;
						}
						else {
							fullscreen = false;
						}
					}
				}
			}
		}
	}
	else {
		cout << "File could not be opened" << endl;
	}
	file.close();
}

void getWindow(SDL_Window*& window, SDL_Renderer*& RENDERER, int width, int height, bool fullscreen , string windowName ) {
	if (window != NULL) {
		SDL_SetWindowSize( window, width, height );
		if (fullscreen) {
			SDL_SetWindowFullscreen( window, SDL_WINDOW_FULLSCREEN );
		}
		else {
			SDL_SetWindowFullscreen( window, 0 );
			SDL_SetWindowPosition( window, SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED );
		}
	}
	else {
		if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
			cout << "Error upon init video" << endl;
		}
		else {
			cout << "Hurray!" << endl;
			//Create window
			if (fullscreen) {
				window = SDL_CreateWindow( windowName.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_FULLSCREEN);	
				if (window != NULL) {
					cout << "Successfully enabled fullscreen" << endl;
				}
				else {
					cout << "Fullscreen could not be initialized" << endl;
					window = SDL_CreateWindow( windowName.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN );
				}
			}
			else {
				cout << "Fullscreen was not selected" << endl;
				window = SDL_CreateWindow( windowName.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN );
			}
			if( window == NULL ){
				cout << "Window could not be created!" << endl;
			}
			else {
				//Get window Renderer
				RENDERER = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
				if (RENDERER != NULL) {
					SDL_SetRenderDrawColor( RENDERER, 0x00, 0x00, 0x00, 0xFF );
					SDL_SetRenderDrawBlendMode(RENDERER , SDL_BLENDMODE_BLEND);
				}
				else {
					printf("Renderer failed to initialize");
				}
			}
		}
	}
}


void renderTextFrame(SDL_Renderer*& RENDERER, SDL_Texture* text, int x, int y) {
	int TW,TH;
	SDL_QueryTexture( text, NULL, NULL, &TW, &TH );
	SDL_Rect rect = {x,y,TW,TH};
	SDL_RenderCopy( RENDERER, text, NULL, &rect);
}

void changeInConfig(string conf, int value) {
	ifstream file ("config.txt");
	//fscanf(file, "%s = %s", name, value);
	string fileContent = "";
	string line, stringValue;
	ostringstream changer;
	changer << value;
	stringValue = changer.str();
	if (file.is_open()) {
		string name;
		int splitPos;
		while (getline(file,line)) {
			if (line.length() > 3) {
				if (line.substr(0,2) != "//") {
					splitPos = line.find(": ");
					name = line.substr(0,splitPos);
					if (name == conf) {
						line = conf + ": " + stringValue;
					}
				}
				fileContent += line + "\n";
			}
		}
	}
	else {
		cout << "File could not be opened" << endl;
	}
	file.close();
	//cout << fileContent << endl;
	ofstream saveFile ("config.txt");
	if (saveFile.is_open()) {
		saveFile << fileContent;
		saveFile.close();
	}
}

void changeInConfig(string conf, bool value) {
	ifstream file ("config.txt");
	//fscanf(file, "%s = %s", name, value);
	string fileContent = "";
	string line, stringValue;
	if (value) {
		stringValue = "true";
	}
	else {
		stringValue = "false";
	}
	if (file.is_open()) {
		string name;
		int splitPos;
		while (getline(file,line)) {
			if (line.length() > 3) {
				if (line.substr(0,2) != "//") {
					splitPos = line.find(": ");
					name = line.substr(0,splitPos);
					if (name == conf) {
						line = conf + ": " + stringValue;
					}
				}
				fileContent += line + "\n";
			}
		}
	}
	else {
		cout << "File could not be opened" << endl;
	}
	file.close();
	//cout << fileContent << endl;
	ofstream saveFile ("config.txt");
	if (saveFile.is_open()) {
		saveFile << fileContent;
		saveFile.close();
	}
}

string toString(int value) {
	string stringValue;
	ostringstream changer;
	changer << value;
	stringValue = changer.str();
	return stringValue;
}

SDL_Texture* loadTexture( SDL_Renderer* RENDERER, string path ) {
	int imgFlags = IMG_INIT_PNG;
	SDL_Texture* texture = NULL;
	if( !( IMG_Init( imgFlags ) & imgFlags ) ) {
		cout << "SDL_Image could not initialize" << endl;
	}
	else {
		SDL_Surface* loadedSurface = NULL;
		loadedSurface = IMG_Load( path.c_str() );
		if( loadedSurface == NULL ){
			cout << "SDL could not load '" << path << "'" << endl;
		}
		else {
        	//Create texture from surface pixels 
        	texture = SDL_CreateTextureFromSurface( RENDERER, loadedSurface );
        	SDL_FreeSurface(loadedSurface);
        	cout << "Image was loaded from: '" << path << "'" << endl;
    	}
	}
	return texture;
}

void playLogo(SDL_Renderer* RENDERER, int width, int height) {
	SDL_Texture* GAMES;
	GAMES = loadTexture(RENDERER, "images/GAMES.png");
	Follow follow(500,255,0);
	int imageWidth = (height/600)*600;
	int imageHeight = (height/600)*300;
	SDL_Rect rect = {
		(width-imageWidth)/2,
		(height-imageHeight)/2,
		imageWidth,
		imageHeight};
	SDL_Event e;
	SDL_SetRenderDrawColor( RENDERER, 0, 0, 0, 255 );
	while (follow.getPoint() > 0) {
		while ( SDL_PollEvent(&e) ) {

		}
		//cout << "WALLA LOOP" << endl;
		SDL_Delay(0);
		SDL_SetRenderDrawColor( RENDERER, 0, 0, 0, 255 );
		SDL_RenderClear(RENDERER);
		SDL_RenderCopy(RENDERER, GAMES, NULL, &rect);
		SDL_SetRenderDrawColor( RENDERER, 0, 0, 0, follow.getPoint() );
		SDL_RenderFillRect(RENDERER , NULL);
		SDL_RenderPresent( RENDERER );
	}
	SDL_Delay(1500);
	follow.reset(500,0,255);
	while (follow.getPoint() < 255) {
		while ( SDL_PollEvent(&e) ) {

		}
		//cout << "WALLA LOOP" << endl;
		SDL_Delay(0);
		SDL_SetRenderDrawColor( RENDERER, 0, 0, 0, 255 );
		SDL_RenderClear(RENDERER);
		SDL_RenderCopy(RENDERER, GAMES, NULL, &rect);
		SDL_SetRenderDrawColor( RENDERER, 0, 0, 0, follow.getPoint() );
		SDL_RenderFillRect(RENDERER , NULL);
		SDL_RenderPresent( RENDERER );
	}
	// fade in "games" image
	// fade out to black
	SDL_DestroyTexture(GAMES);
}