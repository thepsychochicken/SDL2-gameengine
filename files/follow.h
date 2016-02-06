#ifndef _FOLLOW_
	#define _FOLLOW_
	
	class Follow {
		public:
			Follow(int timeToTake,int p1,int p2);
			Follow();
			void reset(int timeToTake,int p1,int p2);
			int getPoint();
		private:
			int startTime,startP,endP,timeT;
	};
#endif