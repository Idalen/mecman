#include "Mecman.cpp"

int main(int argc, char const *argv[])
{
	initscr();
	cbreak();
	noecho();

	int row, col;

	getmaxyx(stdscr, row, col);

	Mecman mecman(col/2, row/2);

	mvprintw(row/2, (col-25)/2, "PRESS ANY KEY TO START...");

	refresh();
	getch();

	mvprintw(row/2, (col-25)/2, "                         ");

	while(TRUE)
	{	

		timeout(0);
		mecman.input();
		mvaddch(mecman.getY(), mecman.getX(), ' ');
		mecman.move();
		mvaddch(mecman.getY(), mecman.getX(), 'C');

		refresh();
	}

	endwin();

	return 0;
}