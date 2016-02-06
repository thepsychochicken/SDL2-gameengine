#ifndef _TIMETAKER_
	#define _TIMETAKER_

	#include <vector>
	#include <string>

	using namespace std;

	class Timetaker {
		private:
			vector < int > times;
			vector <string> names;
			int overallTime;
			int timeFromLastStart; 
		public:
			Timetaker();
			void clear();
			void newStartTime(string);
			void endLastTime();
			string getResult();
	};

#endif