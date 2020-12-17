#include <unistd.h>
#include "Entity.cpp"

#define UP      0
#define LEFT    1
#define DOWN    2
#define RIGHT   3
#define DELAY   0

class Character: public Entity
{

    private:
        int direction;
        int X, Y;

    public:

        explicit Character(int X, int Y, int direction, char icon) : Entity(X, Y)
        {
            this->direction = direction;
            this->X = X;
            this->Y = Y;
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
        int getX(){ return this->X;}
        int getY(){ return this->Y;}
};