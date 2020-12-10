#include <unistd.h>
#include "Entity.cpp"

#define UP      0
#define LEFT    1
#define DOWN    2
#define RIGHT   3
#define DELAY   200000

class Character: public Entity
{
    public:

        explicit Character(int X, int Y, int direction, char icon) : Entity(X, Y)
        {
            this->direction = direction;
            this->icon = icon;
        }

        // Makes the Character move in a certain direction
        void move()
        {
            usleep(DELAY);
            if(this->direction == UP)
                this->Y--;
            else if(this->direction == LEFT)
                this->X--;
            else if(this->direction == DOWN)
                this->Y++;
            else if(this->direction == RIGHT)
                this->X++;
        }

        // "Kills" either the ghost or Mecman, based on if the latter was invincible or not
        // when they touched each other
        virtual void kill() {};

        // Getters/Setters
        int getDirection() {return direction;}
        char getIcon() {return icon;}
        void setDirection(int direction) {this->direction = direction;}
        void setIcon(char icon) {this->icon = icon;}
    
    protected:
        int direction;  // The direction that the character is facing
        char icon;      // The letter that represents the character on the terminal
};