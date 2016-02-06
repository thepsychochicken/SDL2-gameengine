#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <vector>
#include <string>
#include "fontrenderer.h"

using namespace std;

FontRenderer::FontRenderer(string fontName, int size) {
	//Initialize SDL_ttf
    if( TTF_Init() == -1 )
    {
        cout << "TTF could not be initialized" << endl;
    } 
    else {
    	cout << "TTF initialized correctly" << endl;
    } // U happy?
	font = TTF_OpenFont( fontName.c_str(), size );
	if (font == NULL) {
		cout << "'" << fontName << "' with size " << int(size) << " was NOT loaded!" << endl;
	}
}

void FontRenderer::setFont(string fontName, int size) {
	//Initialize SDL_ttf
    if( TTF_Init() == -1 )
    {
        cout << "TTF could not be initialized" << endl;
    } 
    else {
    	cout << "TTF initialized correctly" << endl;
    } // U happy?
	font = TTF_OpenFont( fontName.c_str(), size );
	if (font == NULL) {
		cout << "'" << fontName << "' with size " << int(size) << " was NOT loaded!" << endl;
	}
}

FontRenderer::FontRenderer() {
}

void FontRenderer::newText( string text, int width, SDL_Color textColor, SDL_Renderer *& RENDERER) {
	SDL_Surface* textSurface = TTF_RenderText_Blended( font, text.c_str(), textColor);
	if (textSurface != NULL) {
		SDL_Texture* newText = SDL_CreateTextureFromSurface( RENDERER, textSurface );
		if (newText != NULL) { // Be a good thing
			texts.push_back(text);
			textures.push_back(newText); // Saved to vector before killed
			cout << "Texture succesfully created" << " - Wrote text: '" << text << "'" << endl;
		} // Me looses control when you don't let me use my own computerPÅIK
		else {
			cout << "Could not make Texture!" << endl;
		}
		//SDL_DestroyTexture(newText); // pls try *puppy eyes*
	}
	else {
		cout << "Could not load Font!" << endl;
	}
	SDL_FreeSurface(textSurface);
}

void FontRenderer::renderDynamicText( string text, int width, SDL_Color textColor, SDL_Renderer *& RENDERER, int x, int y ) {
	SDL_Surface* textSurface = TTF_RenderText_Blended( font, text.c_str(), textColor );
	if (textSurface != NULL) {
		SDL_Texture* newText = SDL_CreateTextureFromSurface( RENDERER, textSurface );
		SDL_FreeSurface(textSurface);
		if (newText != NULL) { // Be a good thing
			int TW,TH;
			SDL_QueryTexture( newText, NULL, NULL, &TW, &TH );
			SDL_Rect rect = {x,y,TW,TH};
			SDL_RenderCopy( RENDERER, newText, NULL, &rect);
			SDL_DestroyTexture(newText);
		}
	}
	else {
		SDL_FreeSurface(textSurface);
	}
}

SDL_Texture* FontRenderer::renderText(string name) {
	SDL_Texture* returnTexture = NULL;
	int size = texts.size();
	for (int i = 0; i < size; i++) {
		if (texts[i] == name) {
			returnTexture = textures[i];
			break;
		}
	}
	return returnTexture;
}