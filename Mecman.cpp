#include <iostream>
#include <cstring>
#include <pthread.h>
#include <ncurses.h> /* Biblioteca para o sistema de i/o do jogo. 
					    Documentação em https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/ */
#include "Character.cpp"

class Mecman: public Character
{
    public:

        // Uses parent constructor
        explicit Mecman(int X, int Y) : Character(X, Y, RIGHT) {};

        // Changes Mecman's direction based on the user's input
        void input()
        {
            char key = getch();

            switch(key)
            {
                case 'w':
                    this->direction = UP;
                    break;
                case 'a':
                    this->direction = LEFT;
                    break;
                case 's':
                    this->direction = DOWN;
                    break;
                case 'd':
                    this->direction = RIGHT;
                    break;
            }
        }

        // TODO
        // "Kills" Mecman. Happens when it touches a ghost while not invincible
        void kill()
        {

        }

        // Getters/Setters
        int getInvincibilityTime() {return invincibilityTime;}
        void setInvincibilityTime(int invincibilityTime) {this->invincibilityTime = invincibilityTime;}
    
    protected:
        int invincibilityTime;
};