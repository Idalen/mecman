#include "Mecman.h"
#include "Ghost.h"
#include <thread>

#ifndef GAME_THREADS_H
#define GAME_THREADS_H

void mecman_thread(int id, int* input, Mecman* mecman, Map* map, std::mutex* write_read_m);
void ghost_thread(int id, Ghost* ghost, Map* map, Mecman* mecman, std::mutex* write_read_m);
void input_thread(int id, int* input);

#endif
