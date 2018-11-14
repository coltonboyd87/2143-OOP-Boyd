#include "Group.h"
#include <iostream>
#include <string>

////////////////////////////
//                        //
//     counter Class      //
//      Definition        //
//    *Extends Group*     //
//                        //
////////////////////////////
class counter : public Group {
// private data members and methods 
private:
	int xCordinate;
	int yCordinate;
	int xBounce;
	int yBounce;
	int timeStart; //int to start with for time 
	int timeEnd;   //int to end with for time 
	int time;

	int frameRt; // controls speed of bounces 
	Clock clock; //creates a clock that has already started counting
	Time start; //start instance of Time class 
	Time end;//end instance of Time class
	Time elapsed; //elapsed instance of Time class
	Text text; //text instance 
	Font font; // font instance 

	RectangleShape rectangle; //instance of our Rectangle Shape class

	void setParameterRec(); 
	void setParameterText();
	void wall();

//Public Constructors and methods to work on private data members
public:
	counter();
	counter(int stime, int etime);
	counter(int stime, int etime, float xCoord, float yCord);
	void tUpdate();
	void setColors(Color cClock, Color cBackground, Color cBorder);
	bool End();
};
//End of Class definition 
