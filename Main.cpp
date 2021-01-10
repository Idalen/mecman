#include "GameThreads.h"
#include "Database.h"

/* Funcoes de I/O da biblioteca ncurses, qualquer dúvida ler a 
Documentação em https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/  */ 

WINDOW* create_newmap(int starty, int startx, Map map);
WINDOW *create_newwin(int height, int width, int starty, int startx);
void destroy_win(WINDOW* local_win);

int main(int argc, char const *argv[])
{
	
	WINDOW * my_win;
	
	initscr();  //Inicia a biblioteca
	cbreak();	//Permite o uso de ctrl+c para interromper o programa
	keypad(stdscr, TRUE);
	noecho();
	//nodelay(stdscr, TRUE);
	
	Database db;
	std::mutex write_read_m;

	int max_height, max_width;

	getmaxyx(stdscr, max_height, max_width); //Pega a altura e a largura da sua janela do terminal

	int startx = (max_width - WIDTH)/2, starty = (max_height - HEIGHT)/2;
	int ch = KEY_RIGHT;

	bool on = TRUE;
	while(on)
	{

		Map map;
		Mecman mecman(13, 6, &map);
		Ghost ghost(7, 6, &map);

		my_win = create_newwin(max_height, max_width, starty, startx); 
		mvprintw(starty, startx, 
		"Mecman\n\n Press G to play\n Press R to see the ranking\n Press Q to quit\n\n");
		wrefresh(my_win);

		ch = getch();

		switch(ch){

			case 'g':
			{	
				std::thread t_input(input_thread, 1, &ch, &mecman);	
				std::thread t_ghost(ghost_thread, 2, &ghost, &map, &mecman, &write_read_m);
				std::thread t_mecman(mecman_thread, 3, &ch, &mecman, &map, &write_read_m);

				t_ghost.detach();
				t_mecman.detach();	
				t_input.detach();
				
				while(mecman.isAlive())
				{		
					mvprintw(0, 0, "score: %d", mecman.getScore());

					usleep(DELAY/2);
					destroy_win(my_win);		
					my_win = create_newmap(starty, startx, map);
				}


				destroy_win(my_win);
				db.addScore(mecman.getScore());
				
				break;
			}

			case 'r':
			{	
				mvprintw(starty, startx, "Ranking de jogadores:\n");
				for(int i = 0; i < db.getPlayers(); i++){
					mvprintw(starty+i, startx, "%d) Player %d -- Score: %d\n", i, i, db.getScores(i));
				}
				getch();
				break;
			}
			
			case 'q':{
				on = FALSE;
			}
		}

	}

	endwin(); //finaliza a biblioteca

	return 0;
}

WINDOW *create_newmap(int starty, int startx, Map map)
{	
	WINDOW *local_win;

	local_win = newwin(HEIGHT, WIDTH, starty, startx);
	//wborder(local_win, ' ',' ',' ',' ',' ',' ',' ',' ');				
	wrefresh(local_win);		/* Show that box 		*/

	for(int y = 0; y < HEIGHT; y++)
		for(int x = 0; x < WIDTH; x++)
			mvwaddch(local_win, y, x, map.at(y, x));
	wrefresh(local_win);

	return local_win;
}

WINDOW *create_newwin(int height, int width, int starty, int startx)
{	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	// box(local_win, 0 , 0);		/* 0, 0 gives default characters 
	// 				 * for the vertical and horizontal
	// 				 * lines			*/
	wrefresh(local_win);		/* Show that box 		*/

	return local_win;
}


void destroy_win(WINDOW *local_win)
{	
	/* box(local_win, ' ', ' '); : This won't produce the desired
	 * result of erasing the window. It will leave it's four corners 
	 * and so an ugly remnant of window. 
	 */
	//wborder(local_win,'#','#','#','#','#','#','#','#');
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
