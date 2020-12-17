#include <iostream>
#include <cstring>
#include <pthread.h>
#include "Character.cpp"

class Mecman: public Character
{
    public:

        // Uses parent constructor
        using Character::Character;

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