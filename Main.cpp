#include "Mecman.cpp"

/* Funcoes de I/O da biblioteca ncurses, qualquer dúvida ler a documentacao */ 


int main(int argc, char const *argv[])
{
	initscr();  //Inicia a biblioteca
	cbreak();	//Permite o uso de ctrl+c para interromper o programa
	noecho();	//Nao imprime os caracteres pressionados no terminal

	int row, col; 

	getmaxyx(stdscr, row, col); //Pega a altura e a largura da sua janela do terminal

	Mecman mecman(col/2, row/2); 

	/* printw eh uma funcao analoga ao printf para a biblioteca ncurses 
		mvprintw eh a funcao printw em um ponto (y, x) da tela do terminal
	
		a função refresh precisa ser chamada após todo print
		getch é analogo ao getchar
	*/

	mvprintw(row/2, (col-25)/2, "PRESS ANY KEY TO START..."); 

	refresh();
	getch();

	mvprintw(row/2, (col-25)/2, "                         ");

	while(TRUE)
	{	
		timeout(0);         //faz com que o programa não espere uma entrada do usuario para continuar
		mecman.input();
		mvaddch(mecman.getY(), mecman.getX(), ' ');
		mecman.move();
		mvaddch(mecman.getY(), mecman.getX(), 'C');

		refresh();
	}

	endwin(); //finaliza a biblioteca

	return 0;
}