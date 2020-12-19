#include "Mecman.cpp"
#include "Ghost.cpp"
#include <ncurses.h> /* Biblioteca para o sistema de I/O do jogo. 
					    Documentação em https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/ */

/*class GameThreads
{
	public:

		GameThreads();

		void receiveInput(Mecman mecman)
		{
			while(1)
			{
				timeout(0);
				mecman.input(0); 
				refresh();
			}

			endwin();
		}

		void showMovement(Character character)
		{
			while (1)
			{
				mvaddch(character.getY(), character.getX(), ' ');
				character.move();
				mvaddch(character.getY(), character.getX(), character.getIcon());
			}
		}

		void ghostBehavior(Ghost ghost, Mecman mecman)
		{
			while (1)
			{
				if (mecman.getInvincibilityTime() == 0)
					ghost.chase(mecman);
				else
					ghost.scatter();
			}
		}
};*/