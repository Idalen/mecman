#include "Mecman.h"
#include "Ghost.h"
#include <thread>

#ifndef GAME_THREADS_H
#define GAME_THREADS_H

void mecman_thread(int id, int* input, Mecman* mecman, Map* map);
void ghost_thread(int id, Ghost* ghost, Map* map, Mecman* mecman);
void input_thread(int id, int* input);

#endif
