#include <iostream>
#include <cstring>
#include <pthread.h>
#include "Character.h"
#include "Mecman.h"
#include <ncurses.h> /* Biblioteca para o sistema de i/o do jogo. 
					    Documentação em https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/ */
#ifndef GHOST_H
#define GHOST_H


class Ghost: public Character
{
    public:
        explicit Ghost(int Y, int X, Map* map) : Character(Y, X, map, RIGHT, 'M'){}
        void changeDirection();
        void kill();
        void move(Map* map, Mecman* mecman, std::mutex* write_read_m);
};

#endif
