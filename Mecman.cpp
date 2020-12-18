#include <iostream>
#include <cstring>
#include <pthread.h>
#include "Character.cpp"
#include <ncurses.h> /* Biblioteca para o sistema de i/o do jogo. 
					    Documentação em https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/ */

class Mecman: public Character
{
    public:

        // Uses parent constructor
        explicit Mecman(int X, int Y) : Character(X, Y, RIGHT) {};

        // TODO
        // "Kills" Mecman. Happens when it touches a ghost while not invincible
        void kill()
        {

        }

        void input(int ch)
        {
            switch(ch)
            {	
                case KEY_LEFT:				
                    setDirection(LEFT);
                    break;
                case KEY_RIGHT:				
                    setDirection(RIGHT);
                    break;
                case KEY_UP:				
                    setDirection(UP);
                    break;
                case KEY_DOWN:
                    setDirection(DOWN);
                    break;
            }
        }

        // Getters/Setters
        int getInvincibilityTime() {return invincibilityTime;}
        void setInvincibilityTime(int invincibilityTime) {this->invincibilityTime = invincibilityTime;}
    
    protected:
        int invincibilityTime;
};