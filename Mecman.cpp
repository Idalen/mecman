#include <iostream>
#include <cstring>
#include <pthread.h>
#include "Character.cpp"

class Mecman: public Character
{
    public:

        // Uses parent constructor
        using Character::Character;

        // Changes Mecman's direction based on the user's input
        void input(char key)
        {
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