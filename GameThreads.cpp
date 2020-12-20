#include "GameThreads.h"


void mecman_thread(int id, int* input, Mecman* mecman, Map* map, std::mutex* write_read_m){

	while(TRUE)
	{
		mecman->input(*input);

		mecman->move(map, write_read_m);

		mvprintw(2, 0, "%d %d %d", mecman->getY(), mecman->getX() , *input);
	}

}

void ghost_thread(int id, Ghost* ghost, Map* map, Mecman* mecman, std::mutex* write_read_m){

	while (TRUE)
	{
		ghost->changeDirection();

		ghost->move(map, mecman, write_read_m);

		mvprintw(4, 0, "%d %d", ghost->getY(), ghost->getX());
	}
	
}

void input_thread(int id, int* input){

	while(TRUE)
		*input = getch();
}
