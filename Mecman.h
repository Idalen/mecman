#include <iostream>
#include <cstring>
#include <pthread.h>
#include "Character.h"
#include <ncurses.h> /* Biblioteca para o sistema de i/o do jogo. 
					    Documentação em https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/ */

class Mecman: public Character
{
    private:
        bool alive = TRUE;

    public:
        explicit Mecman(int Y, int X, Map* map) : Character(Y, X, map, RIGHT, 'C'){}
        void kill();
        void input(int ch);
        void move(Map* map);
        bool isAlive();
    
};