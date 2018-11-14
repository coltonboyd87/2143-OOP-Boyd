#include "counter.h"


////////////////////////////
//                        //
//     counter Class      //
//    Implementation      //
//    *Extends Group*     //
//                        //
////////////////////////////

/*
* Method Name: counter()
* @param: None 
* This is our default constructor for our counter class w/no 
* params. 
*/
counter::counter() {
	xCordinate = 50;
	yCordinate = 50;

	frameRt = 0; //Frame Rate 

	//-X coordinate collision 
	if (xCordinate == 50) {
		xBounce = -1;
	}
	//+X coordinate collision 
	else if (xCordinate == 450) {
		xBounce = 1;
	}

	//-Y coordinate collision 
	if (yCordinate == 50) {
		yBounce = -1;
	}
	//+Y coordinate collision 
	else if (yCordinate == 350) {
		yBounce = 1;
	}

	start = seconds(0.0);
	timeStart = 0.0;
	end = seconds(50.0);
	timeEnd = 0.0;

	//Restarts the clocks
	clock.restart();
	elapsed = clock.getElapsedTime();

	time = start.asSeconds();
	text.setString(to_string(time));

	//Loads font 
	if (!font.loadFromFile("Segment7Standard.otf"))
	{
		cout << "error loading font";
	}

	setParameterRec();
	setParameterText();

	//pushes drawable items onto the group draw vector
	this->push_back(rectangle);
	this->push_back(text);
}



/*
* Method Name: counter()
* @param: 2 ints, stime, etime
* This is our constructor for our counter class
* start time and end time are passed in. 
*/
counter::counter(int stime, int etime) {
	xCordinate = 50.0;
	yCordinate = 50.0;

	frameRt = 0; //Frame Rate 

	//-X coordinate collision 
	if (xCordinate == 50) {
		xBounce = -1;
	}
	//+X coordinate collision 
	else if (xCordinate == 450) {
		xBounce = 1;
	}

	//-Y coordinate collision 
	if (yCordinate == 50) {
		yBounce = -1;
	}
	//+Y coordinate collision 
	else if (yCordinate == 350) {
		yBounce = 1;
	}

	start = seconds(stime);
	timeStart = stime;
	end = seconds(etime);
	timeEnd = etime;

	//Restarts the clock
	clock.restart();
	elapsed = clock.getElapsedTime();

	time = start.asSeconds();
	text.setString(to_string(time));

	//Loads font
	if (!font.loadFromFile("Segment7Standard.otf"))
	{
		cout << "error loading font";
	}

	setParameterRec();
	setParameterText();

	//pushes drawable items onto the group draw vector
	this->push_back(rectangle);
	this->push_back(text);
}



/*
* Method Name: counter()
* @param: 2ints - stime,etime
* 2 floats xCoord,yCoord passed in by user. 
*/
counter::counter(int stime, int etime, float xCoord, float yCoord) {
	xCordinate = xCoord;
	yCordinate = yCoord;

	frameRt = 0; //Frame Rate 

	//-X coordinate collision 
	if (xCordinate == 50) {
		xBounce = -1;
	}
	//+X coordinate collision 
	else if (xCordinate == 450) {
		xBounce = 1;
	}

	//-Y coordinate collision 
	if (yCordinate == 50) {
		yBounce = -1;
	}
	//+Y coordinate collision 
	else if (yCordinate == 350) {
		yBounce = 1;
	}

	start = seconds(stime);
	timeStart = stime;
	end = seconds(etime);
	timeEnd = etime;

	//Restarts the clocks 
	clock.restart();
	elapsed = clock.getElapsedTime();

	time = start.asSeconds();
	text.setString(to_string(time));

	//Loads font
	if (!font.loadFromFile("Segment7Standard.otf"))
	{
		cout << "error loading font";
	}

	setParameterRec();
	setParameterText();

	//pushes drawable items onto the group draw vector
	this->push_back(rectangle);
	this->push_back(text);
}



/*
* Method Name: setParameterRec
* 	setting of rectangle's color, size, origin, and position
* @param:none
* @returns:none
*/
void counter::setParameterRec() {
	rectangle.setSize(Vector2f(100, 100));
	rectangle.setFillColor(Color::White);
	rectangle.setOutlineColor(Color::Red);
	rectangle.setOutlineThickness(3);
	rectangle.setOrigin(50, 50);
	rectangle.setPosition(xCordinate, yCordinate);
	return;
}



/*
* Method Name: setParameterText
* 	setting of Texts' color, size, origin, and position
* @param:none
* @returns:none
*/
void counter::setParameterText() {
	text.setFont(font);
	text.setCharacterSize(50);
	text.setFillColor(Color::Black);
	text.setOrigin(24, 24);
	text.setPosition(xCordinate, yCordinate);
	return;
}



/*
* Method Name: wall()
* 	collision bounce
* @param:none
* @returns:none
*/
void counter::wall() {
	//-X coordinate collision 
	if (xCordinate == 50) {
		xBounce = -1;
	}
	//+X coordinate collision
	else if (xCordinate == 450) {
		xBounce = 1;
	}

	//-Y coordinate collision 
	if (yCordinate == 50) {
		yBounce = -1;
	}
	//+Y coordinate collision 
	else if (yCordinate == 350) {
		yBounce = 1;
	}

	//change of location
	xCordinate -= xBounce;
	yCordinate -= yBounce;
	//location of set 
	rectangle.setPosition(xCordinate, yCordinate);
	text.setPosition(xCordinate, yCordinate);
}



/*
* Method Name: tUpdate
* 	calculation of time and returns it to window to print 
* @param:none
* @returns:none
*/
void counter::tUpdate() {

	if (time == timeEnd) { 
		time = end.asSeconds();
		text.setString(to_string(time));
	}
	else if (timeStart > timeEnd) { 
		elapsed = clock.getElapsedTime();
		time = start.asSeconds() - elapsed.asSeconds();
		text.setString(to_string(time));
	}
	else if (timeStart > 0) { 
		elapsed = clock.getElapsedTime();
		time = start.asSeconds() - elapsed.asSeconds();
		text.setString(to_string(time));
	}
	else { 
		elapsed = clock.getElapsedTime();
		time = start.asSeconds() + elapsed.asSeconds();
		text.setString(to_string(time));
	}

	 
	if (frameRt == 25) {
		wall();        //changes location of clock
		frameRt = 0;
	}
	else {
		frameRt++; //Increment frameRt
	}
	return;
}



/*
* Method Name: setColors
* 	sets the colors of the clock, the background, and the border
* @param:color clock, background, border
* @returns:none
*/
void counter::setColors(Color cClock, Color cBackground, Color cBorder) {
	text.setFillColor(cClock);
	rectangle.setFillColor(cBackground);
	rectangle.setOutlineColor(cBorder);
}



/*
* Function: End
* 	checks to see if the clock has reached end time
* @param:
*	none
* @returns:
*   none
*/
bool counter::End() {
	if (time == timeEnd) {
		return true;
	}
	else return false;
}
//End of counter Implementation

