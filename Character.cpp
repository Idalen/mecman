#include "Entity.cpp"

#define UP      0  
#define LEFT    1
#define DOWN    2
#define RIGHT   3
#define DELAY   200000

class Character: public Entity
{
    public:

        explicit Character(int X, int Y, int direction) : Entity(X, Y)
        {
            this->direction = direction;
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

        // "Kills" either the ghost or Mecman, based if the latter was invincible or not
        // when they touched
        virtual void kill();

        // Getters/Setters
        int getDirection() {return direction;}
        void setDirection(int direction) {this->direction = direction;}
    
    protected:
        int direction;
};