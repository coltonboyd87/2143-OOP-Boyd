/*
*Course: CMPS 2143 - OOP
*Program: A06
*Purpose: Clock made from SFML classes that can be used to count up or down. This clock 
* extends Group to then become drawable 
*
*@author Colton Boyd 
*@version 1.1 11/13/18
*@github: coltonboyd87
*/

#include "counter.h"

using namespace std;
using namespace sf;


//////////////////////
//                  //
//      Main        //
//     Function     // 
//                  //
//////////////////////
int main()
{
	RenderWindow window(VideoMode(500, 400), "SFML Clock");
	counter clock1(25, 0, 50, 50);
	clock1.setColors(Color::Black, Color::White, Color::Red);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		if (window.isOpen() && clock1.End())
			window.close();

		window.clear();
		window.draw(clock1);
		clock1.tUpdate();
		window.display();
	}
	return 0;
}
//End main