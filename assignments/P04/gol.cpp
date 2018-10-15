/**
*  Course: CMPS 2143 - OOP
*  Program: Program P04 - Game of Life (John Conway) 
*
* 
*  @author Colton Boyd 
*  @version 1.1 10/15/18
*  @github username: coltonboyd87
*/


//Headers used in P04
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <exception>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

//Libraries used on P04
using namespace sf;
using namespace std;




/**
  * Name: golCell
  * struct that packages data elements together for our GOL cell. 
  *
  * @param  {None}
  * @return {NULL}
 */
struct golCell {
	bool isAlive;
	int neighborCount;
	RectangleShape Rect;
	int width;
	int height;
	
	//Constructor for our gol Cell 
	golCell() {
		isAlive = 0;
		neighborCount = 0;
		width = 10;
		height = 10;	
		Rect.setSize(sf::Vector2f(width, height));
		Rect.setFillColor(Color::Cyan);
		Rect.setOutlineColor(Color::Black);
		Rect.setOutlineThickness(1);
	}
	void setCellPos(int x, int y) {
		Rect.setPosition(x*width, y*height);
	}
	void changeColor(Color nameOfColor) {
		Rect.setFillColor(nameOfColor);
	}
};



////////////////////////////////
//                            //
//     Game Of Life           //
//     Definition             //
//                            //
//                            //
////////////////////////////////
class GameOfLife {
private:
	golCell* World;	//Private variables to be implemented with. 
	int nums[10];
	int id;
public:
	golCell ** W;
	int width;		
	int height;		
	int wRows;	//Public variables 
	int wCols;	
	int frameCount;	
	int framert;	


	RenderWindow Window;
	string ofileName;		//Methods to manipulate the variables
	void printWorld(string);
	bool onWorld(int, int);
	int countNeighbors(int, int);
	void applyRules(int, int);
	ifstream fileRead(string);
	golCell** arrayBuild(ifstream&);
	void goNextGen(int);
	void run(string, string, string);


	~GameOfLife(); //Deconstructor
	GameOfLife(int width, int height);
	GameOfLife(int width, int height, int rt);
	void drawWorld();
};



/////////////////////////////////
//							   //
//	    Game Of Life		   //
//	   Implementation		   //
//							   //
//							   //
/////////////////////////////////
/**
* Name:GameOfLife()
* Constructor that creates the game board
* 
*
* @param {int}  width: width of the Window
*				height: height of the window
* @return {NULL}
*/
GameOfLife::GameOfLife(int width, int height) {
	World = new golCell[height];
	id = 0;
	frameCount = 0;
	framert = 50; 
	width = width;	//width of window
	height = height; //height of window 

	// Creation of our window
	Window.create(VideoMode(width, height), "Game of Life");

	for (int i = 0; i < height; i++) {
		W[i] = new golCell[width];
		for (int j = 0; j < width; j++) {
			W[i][j].setCellPos(i, j);
		}
	}
}



/**
* Name: GameOfLife()
* Constructor that creates the game board
*
* @param {int}  width: width of the Window
*				height: height of the window
*				rt: User inputs the rt for amount of interations
* @return {NULL}
*/
GameOfLife::GameOfLife(int width, int height, int rt) {
	width = width;
	height = height;
	frameCount = 0;
	 
	framert = rt;
	Window.create(VideoMode(width, height), "Game of Life");

	W = new golCell*[height];
	id = 0;

	for (int i = 0; i < height; i++) {
		W[i] = new golCell[width];
		for (int j = 0; j < width; j++) {
			W[i][j].setCellPos(i, j);
		}
	}
}



/**
* Name: ~GameOfLife
* Deconstructor
* Safely deletes elements
*
* @param {int}
* @return {NULL}
*/
GameOfLife::~GameOfLife() {
	for (int i = 0; i < wRows; i++) { 
		delete[]W[i];
	}
	delete[]W;
}



/**
  * Name: drawWorld()
  * Prints the state of the gol world
  * to the Console and to SFML.
  *
  * @param {None}
  * @return {NULL}
  */
void  GameOfLife::drawWorld() {
	Window.clear();
	for (int i = 0; i < wRows; i++) {
		for (int j = 0; j < wCols; j++) {
			Window.draw(W[i][j].Rect);
		}
	}
	
	for (int i = 0; i < wRows; i++) {
		for (int j = 0; j < wCols; j++) {
			cout << *(&W[i][j].isAlive) << "";
		}
		cout << endl;
	}
	sleep(milliseconds(500));
	Window.display();
}



/**
* Name: countNeighbors
* Counts the live neighborCount for a given cell	
*
* @param {int} r: row we're looking at c: column we're looking at
* @return {int} neighborCount: sum of neighbours
*/
int GameOfLife::countNeighbors(int r, int c) {
	int neighborCount = 0;
	if (onWorld(r - 1, c - 1) && W[r - 1][c - 1].isAlive) {
		neighborCount++;
	}
	if (onWorld(r - 1, c) && W[r - 1][c].isAlive) {
		neighborCount++;
	}
	if (onWorld(r - 1, c + 1) && W[r - 1][c + 1].isAlive) {
		neighborCount++;
	}
	if (onWorld(r, c - 1) && W[r][c - 1].isAlive) {
		neighborCount++;
	}
	if (onWorld(r, c + 1) && W[r][c + 1].isAlive) {
		neighborCount++;
	}
	if (onWorld(r + 1, c - 1) && W[r + 1][c - 1].isAlive) {
		neighborCount++;
	}
	if (onWorld(r + 1, c) && W[r + 1][c].isAlive) {
		neighborCount++;
	}
	if (onWorld(r + 1, c + 1) && W[r + 1][c + 1].isAlive) {
		neighborCount++;
	}
	return neighborCount;
}



/**
  * Name: onWorld
  * Checks to see if a cell is on the World or not
  *
  * @param {object , int} row: row we're looking at col: column we're looking at
  * @return {int} neighborCount: sum of neighbours
  */
bool GameOfLife::onWorld(int row, int col) {
	if ((row >= 0 && row < wRows) && (col >= 0 && col < wCols)) {
		return true;
	}
	else {
		return false;
	}
}


/**
 * Name: applyRules
 * Apply rules to kill the cell or bring it to life
 *
 * @param {object , int} row: row we're looking at col: column we're looking at
 * @return {NULL}
 */
void GameOfLife::applyRules(int row, int col) {
	W[row][col].neighborCount;
	// Rule 1: Any live cell with fewer than two live neighborCount dies,as if caused by under-population.
	if (W[row][col].isAlive == true && W[row][col].neighborCount < 2) {
		W[row][col].isAlive = false;
		W[row][col].setCellPos(row, col);
		W[row][col].changeColor(Color::Black);
	}
	// Rule 2: Any live cell with more than three live neighborCount dies, as if by overcrowding.
	if (W[row][col].isAlive == true && W[row][col].neighborCount > 3) {
		W[row][col].isAlive = false;
		W[row][col].setCellPos(row, col);
		W[row][col].changeColor(Color::Black);
	}
	// Rule 3: Any live cell with two or three live neighborCount lives on to the next generation.
	if (W[row][col].isAlive == true && W[row][col].neighborCount == 2 || W[row][col].neighborCount == 3) {
		W[row][col].isAlive = true;
		W[row][col].setCellPos(row, col);
		W[row][col].changeColor(Color::Blue);
	}
	// Rule 4: Any dead cell with exactly three live neighborCount becomes a live cell.
	if (W[row][col].isAlive == false && W[row][col].neighborCount == 3) {
		W[row][col].isAlive = true;
		W[row][col].setCellPos(row, col);
		W[row][col].changeColor(Color::Blue);
	}
	else {
		W[row][col].isAlive = W[row][col].isAlive;

		if (W[row][col].isAlive == true) {
			W[row][col].setCellPos(row, col);
			W[row][col].changeColor(Color::Blue);
		}
		else if (W[row][col].isAlive == false) {
			W[row][col].setCellPos(row, col);
			W[row][col].changeColor(Color::Black);
		}

	}
}



/**
 * Name: fileRead()
 * Attempting to open the file
 *
 * @param {string} fileName: the name of the file to be read in
 * @return {ifstream} infile: reference to the file we will be using
 */
ifstream GameOfLife::fileRead(string fileName) {
	ifstream infile;
	infile.open(fileName);
	if (!infile) {
		exit(1);
	}
	return infile;
}



/**
 * Name: arrayBuild
 * Attempt to build our initial Array and print it to the screen
 *
 * @param {ifstream } infile: the file we will be using
 * @return {object} W: initial world
 */
golCell** GameOfLife::arrayBuild(ifstream& infile) {
	//Reading generation 0 for our game to be played. 
	//And the number of rows and columns
	infile >> wRows >> wCols;
	W = new golCell*[wRows];
	for (int i = 0; i < wRows; i++) {
		W[i] = new golCell[wCols];
	}
	int** tempArray = new int *[wRows];

	for (int i = 0; i < wRows; i++) {
		tempArray[i] = new int[wCols];
	}
	char x;
	string myString = "";
	while (!infile.eof()) {
		x = infile.get();
		if (x == '1' || x == '0') {
			myString = myString + x;
		}
	}
	char * characterArray = new char[myString.length() + 1];
	strcpy_s(characterArray, myString.length() + 1, myString.c_str());
	
	int k = 0;
	for (int i = 0; i < wRows; i++) {
		for (int j = 0; j < wCols; j++) {
			tempArray[i][j] = (int)characterArray[k] - 48;
			k++;
		}
	}
	for (int i = 0; i < wRows; i++) {
		for (int j = 0; j < wCols; j++) {
			W[i][j].isAlive = tempArray[i][j];
			if (W[i][j].isAlive == true) {
				W[i][j].setCellPos(i, j);
				W[i][j].changeColor(Color::Blue);
			}
			else if (W[i][j].isAlive == false) {
				W[i][j].setCellPos(i, j);
				W[i][j].changeColor(Color::Black);
			}
		}
	}

	drawWorld();
	return W;

}



/**
 * Name: goNextGen
 * Refreshes the generations then prints the new generation.
 *
 * @param {int} runAmt: the number of times the program will run
 * @return {Null}
 */
void GameOfLife::goNextGen(int runAmt) {
	//Change the states x amount of times 
	for (int x = 0; x < runAmt; x++) {
		for (int i = 0; i < wRows; i++) {
			for (int j = 0; j < wCols; j++) {
				W[i][j].neighborCount = countNeighbors(i, j);
			}

		}
		for (int i = 0; i < wRows; i++) {
			for (int j = 0; j < wCols; j++) {
				applyRules(i, j);
			}

			if (x == 337) {
				printWorld(ofileName);
			}
		}
		//Printing New World  
		cout << "Printing Array to Draw: " << endl;
		cout << "This is the  : " << x + 1 << " run" << endl;
		drawWorld();
	}
}


/**
  * Prints the Final generation to outfile.
  *
  * @param {None}
  * @return {NULL}
  */
void  GameOfLife::printWorld(string ofileName) {
	ofstream myfile;
	myfile.open(ofileName);
	myfile << " Course: CMPS 2143 - OOP " << endl;
	myfile << " Program: Program P04 - Game of Life (John Conway) " << endl;
	myfile << "                       " << endl;
	myfile << " @author: Colton Boyd " << endl;
	myfile << " @version 1.1 10/15/18 " << endl;
	myfile << " @github username: coltonboyd87" << endl << endl;
	myfile << " The 338th generation" << endl;

	// Print to file
	for (int i = 0; i < wRows; i++) {
		for (int j = 0; j < wCols; j++) {
			myfile << *(&W[i][j].isAlive) << "";
		}
		myfile << endl;
	}
	myfile.close();
}



/**
* Name: run 
* Driver for the Game of life program , accepts arguements
*
* @param {string} inputFileName: name of the file we're accessing
*				  numberOfRuns:  the number of generations we will genert
*				  outputFileName: output file for the program
* @return {NULL}
*/
void GameOfLife::run(string inputFileName, string numberOfRuns, string outputFileName) {
	ofileName = outputFileName; 
	ifstream fileStream;
	try {
		fileStream = fileRead(inputFileName);
	}
	catch (exception& e) {
		exit(1);
	}

	// Reading file 
	fileStream = fileRead(inputFileName);
	// Builds generation 1 
	golCell** World = arrayBuild(fileStream);
	// Convert to int
	int numGen = stoi(numberOfRuns);
	// update gen 
	goNextGen(numGen);

}



////////////////////////////////////////
//                                    //
//            Main                    //
//          Function                  //
//                                    //
//                                    //
////////////////////////////////////////
int main(int argc, char *argv[]) {  
	int rt = 10;
	GameOfLife Gol(400, 500, rt);

	//Gol World;
	string ifileName;
	string numGen;
	string ofileName;

	if (argc < 4) {
		cout << "usage: " << argv[0] << " <filename>\n";
	}
	else {
		ifileName = argv[1];
		numGen = argv[2];	// Runs the driver fuction of the program 
		ofileName = argv[3];
		//Gol.run(ifileName, numGen, ofileName);
	}
	while (Gol.Window.isOpen()) {
		Event event;
		while (Gol.Window.pollEvent(event)) {
			if (Gol.frameCount % Gol.framert == 0) {
		
				Gol.run(ifileName, numGen, ofileName);
			}
			//Gol.drawWorld();
			if (event.type == Event::Closed) {
				Gol.Window.close();
			}

		}
		Gol.frameCount++;
	}
	return 0;
}


