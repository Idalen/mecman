#include <ncurses.h> /* Biblioteca para o sistema de i/o do jogo. 
					    Documentação em https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/ */
#include "Mecman.cpp"
#include "Map.cpp"

/* Funcoes de I/O da biblioteca ncurses, qualquer dúvida ler a 
Documentação em https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/  */ 

WINDOW* create_newwin(int starty, int startx, Map map);
void destroy_win(WINDOW* local_win);

int main(int argc, char const *argv[])
{
	
	WINDOW * my_win;
	
	initscr();  //Inicia a biblioteca
	cbreak();	//Permite o uso de ctrl+c para interromper o programa
	keypad(stdscr, TRUE);
	
	Map map;
	int max_height, max_width;

	getmaxyx(stdscr, max_height, max_width); //Pega a altura e a largura da sua janela do terminal

	int startx = (max_width - map.getWidth())/2, starty = (max_height - map.getHeight())/2;
	int ch;

	my_win = create_newwin(starty, startx, map); 

	while(true){
		
		destroy_win(my_win);
		my_win = create_newwin(starty, startx, map);

	} 

	endwin(); //finaliza a biblioteca

	return 0;
}

WINDOW *create_newwin(int starty, int startx, Map map)
{	
	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	wborder(local_win, '#', '#', '#','#','#','#','#','#');				
	wrefresh(local_win);		/* Show that box 		*/

	for(int y = 0; y < map.getHeight(); y++)
		for(int x = 0; map.getWidth(); x++)
			mvwaddch(local_win, y, x, map.at(y, x));
	wrefresh(local_win);

	return local_win;
}

void destroy_win(WINDOW *local_win)
{	
	/* box(local_win, ' ', ' '); : This won't produce the desired
	 * result of erasing the window. It will leave it's four corners 
	 * and so an ugly remnant of window. 
	 */
	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	/* The parameters taken are 
	 * 1. win: the window on which to operate
	 * 2. ls: character to be used for the left side of the window 
	 * 3. rs: character to be used for the right side of the window 
	 * 4. ts: character to be used for the top side of the window 
	 * 5. bs: character to be used for the bottom side of the window 
	 * 6. tl: character to be used for the top left corner of the window 
	 * 7. tr: character to be used for the top right corner of the window 
	 * 8. bl: character to be used for the bottom left corner of the window 
	 * 9. br: character to be used for the bottom right corner of the window
	 */
	wrefresh(local_win);
	delwin(local_win);
}