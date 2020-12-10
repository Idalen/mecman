#include <thread>
#include "Blinky.cpp"
#include "Pinky.cpp"
#include "Inky.cpp"
#include "Clyde.cpp"
#include "Scoreboard.cpp"
#include "GameThreads.cpp"
using namespace std;

// Prints the game inital screen
void gameStart(int width, int height)
{
	mvprintw(width/2, (height-25)/2, "PRESS ANY KEY TO START..."); 
	refresh();
	getch();
	mvprintw(width/2, (height-25)/2, "                         ");
}

// Prints the game over screen
void gameOver(int width, int height)
{
	mvprintw(width/2, (height-25)/2, "GAME OVER"); 
	refresh();
	getch();
	mvprintw(width/2, (height-25)/2, "                         ");
}

int main(int argc, char const *argv[])
{
	initscr();  // Initializes the library
	cbreak();	// Allows the usage of ctrl+c to interrupt the program
	noecho();	// Makes it so that pressed characters are not printed in the terminal

	// Receives the width and height of the screen
	int width, height;
	getmaxyx(stdscr, width, height);

	gameStart(width, height); // Shows the starting screen

	// Initializes the classes
	Mecman mecman(height/2, width/2, RIGHT, 'M');
	// TODO Set default spawning coordinates and direction for ghosts
	Blinky blinky(0,0,0, 'B');
	Pinky pinky(0,0,0, 'P');
	Inky inky(0,0,0, 'I');
	Clyde clyde(0,0,0, 'C');
	Scoreboard scoreboard(3,0,1);

	// Initializes the game threads
	thread one(GameThreads::receiveInput, mecman); 				// Receives user input for Mecman's movement
	thread two(GameThreads::showMovement, mecman);				// Shows Mecman moving
	thread three(GameThreads::ghostBehavior, blinky, mecman); 	// Initializes ghost behavior
	thread four(GameThreads::ghostBehavior, pinky, mecman);
	thread five(GameThreads::ghostBehavior, inky, mecman);
	thread six(GameThreads::ghostBehavior, clyde, mecman);
	thread seven(GameThreads::showMovement, blinky);			// Shows ghosts moving
	thread eight(GameThreads::showMovement, pinky);
	thread nine(GameThreads::showMovement, inky);
	thread ten(GameThreads::showMovement, clyde);

	// If Mecman touches a ghost, subtracts a life or ends the game
	while(TRUE)
		if (mecman.touching(blinky) | mecman.touching(pinky) 
			| mecman.touching(inky) | mecman.touching(clyde))
		{	
			mecman.kill(); // Kills Mecman

			// If Mecman has no lives left, ends the game
			if (scoreboard.getLives() < 0)
			{	
				// Terminates the game threads
				thread(one);
				thread(two);
				thread(three);
				thread(four);
				thread(five);
				thread(six);
				thread(seven);
				thread(eight);
				thread(nine);
				thread(ten);

				gameOver(width, height); // Shows the game over screen

				break; // Ends the game loop
			}

			// Subtracts a life
			scoreboard.setLives(scoreboard.getLives()-1);
		}

	endwin(); // Closes the library

	return 0;
}