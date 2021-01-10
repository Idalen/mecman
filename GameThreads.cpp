#include "GameThreads.h"


void mecman_thread(int id, int* input, Mecman* mecman, Map* map, std::mutex* write_read_m){

	while(mecman->isAlive())
	{
		usleep(DELAY);
		
		write_read_m->lock();
		
		mecman->input(*input);
		mecman->move(map);

		write_read_m->unlock();

	}

}

void ghost_thread(int id, Ghost* ghost, Map* map, Mecman* mecman, std::mutex* write_read_m){

	while (mecman->isAlive())
	{

		usleep(DELAY);

		write_read_m->lock();
		
		ghost->changeDirection(map);
		ghost->move(map, mecman);
		
		write_read_m->unlock();
	}
	
}

void input_thread(int id, int* input, Mecman* mecman){

	while(mecman->isAlive())
		*input = getch();
}
