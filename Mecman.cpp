#include "Mecman.h"


class Mecman: public Character
{     
        
    public:
            
        bool alive = TRUE;
        // Uses parent constructor
        explicit Mecman(int Y, int X, Map* map) : Character(Y, X, map, RIGHT, 'C') {};

        // TODO
        // "Kills" Mecman. Happens when it touches a ghost while not invincible
        void kill()
        {
            this->alive = FALSE;
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

        void move(Map* map){
            
            if(map->at(this->Y, this->X) == 'M')
                this->alive = FALSE;

            Character::move(map);

            if(map->at(this->Y, this->X) == 'M')
                this->alive = FALSE;
        }

        bool isAlive(){
            return this->alive;
        }

        // Getters/Setters
        int getInvincibilityTime() {return invincibilityTime;}
        void setInvincibilityTime(int invincibilityTime) {this->invincibilityTime = invincibilityTime;}
    
    protected:
        int invincibilityTime;
};
