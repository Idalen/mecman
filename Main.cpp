#include <ncurses.h> /* Biblioteca para o sistema de I/O do jogo. 
					    Documentação em https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/ */
#include "Mecman.cpp"

int main(int argc, char const *argv[])
{
	initscr();  // Inicia a biblioteca
	cbreak();	// Permite o uso de ctrl+c para interromper o programa
	noecho();	// Nao imprime os caracteres pressionados no terminal

	int row, col;

	getmaxyx(stdscr, row, col); // Pega a altura e a largura da janela do terminal

	Mecman mecman(col/2, row/2); 

	// Printa a mensagem inicial no centro do terminal
	mvprintw(row/2, (col-25)/2, "PRESS ANY KEY TO START..."); 
	refresh(); // Mostra o resultado da modificação da tela

	getch();

	mvprintw(row/2, (col-25)/2, "                         ");

	while(TRUE)
	{	
		timeout(0);         // Faz com que o programa não espere uma entrada do 
							// usuario para continuar
		mecman.input(getch());
		mvaddch(mecman.getY(), mecman.getX(), ' ');
		mecman.move();
		mvaddch(mecman.getY(), mecman.getX(), 'C');

		refresh();
	}

	endwin(); // Finaliza a biblioteca

	return 0;
}