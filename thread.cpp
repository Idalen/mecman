#include <iostream>
#include <cstring>
#include <pthread.h>
#include <unistd.h>
#include <ncurses.h> /* biblioteca para o sistema de i/o do jogo. 
						Documentação em https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/ */

#define UP     0  
#define RIGHT  1
#define DOWN   2
#define LEFT   3
#define DELAY  200000

class Pacman 
{
	
private:
	int x, y, direction;

public:

	Pacman(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	void Input()
	{
		char key = getch();

		switch(key)
		{
			case 'w':
				this->direction = UP;
				break;
			case 'd':
				this->direction = RIGHT;
				break;
			case 's':
				this->direction = DOWN;
				break;
			case 'a':
				this->direction = LEFT;
				break;
			case 'q':
				break;	
		}
		
	}

	void Move()
	{
		usleep(DELAY);
		if(this->direction == UP)
			this->y = this->y - 1;
		else if(this->direction == RIGHT)
			this->x = this->x + 1;
		else if(this->direction == DOWN)
			this->y = this->y + 1;
		else if(this->direction == LEFT)
			this->x = this->x - 1;
	}

	int Getx()
	{
		return this->x;
	}
	
	int Gety()
	{
		return this->y;
	}
};






int main(int argc, char const *argv[])
{

	initscr();
	cbreak();
	noecho();

	int row, col;

	getmaxyx(stdscr, row, col);

	Pacman pacman(col/2, row/2);

	mvprintw(row/2, (col-25)/2, "PRESS ANY KEY TO START...");

	refresh();
	getch();

	mvprintw(row/2, (col-25)/2, "                         ");

	while(TRUE)
	{	

		timeout(0);
		pacman.Input();
		mvaddch(pacman.Gety(), pacman.Getx(), ' ');
		pacman.Move();
		mvaddch(pacman.Gety(), pacman.Getx(), 'C');

		refresh();
	}

	endwin();

	return 0;
}