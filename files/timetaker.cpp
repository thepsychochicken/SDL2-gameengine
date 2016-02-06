#include <SDL2/SDL.h>
#include <sstream>
#include <string>
#include <vector>
#include "timetaker.h"

using namespace std;


Timetaker::Timetaker() {
	overallTime = 0;
	timeFromLastStart = SDL_GetTicks();
}

void Timetaker::clear() {
	times.clear();
	names.clear();
	overallTime = 0;
}

void Timetaker::newStartTime(string name) {
	names.push_back(name);
	timeFromLastStart = SDL_GetTicks();
}

void Timetaker::endLastTime() {
	times.push_back(SDL_GetTicks()-timeFromLastStart);
	overallTime+=SDL_GetTicks()-timeFromLastStart;
}

string Timetaker::getResult() {
	if (overallTime == 0) {
		return "Error: Cannot divide with 0";
	}
	string result;
	int size = times.size();
	for (int i = 0; i < size; i++) {
		stringstream newS;
		newS << names[i] << " took: " << int ((double)times[i]/overallTime*100) << "%\n";
		result+=newS.str();
	}
	return result;
}