#include <unistd.h>
#include "Map.cpp"

#define UP      0
#define LEFT    1
#define DOWN    2
#define RIGHT   3
#define DELAY   0

class Character
{
    protected:
        int direction, X, Y;
        char icon;

    public:

        explicit Character(int X, int Y, int direction)
        {
            this->direction = direction;
            this->X = X;
            this->Y = Y;
        }

        // Makes the Character move in a certain direction
        void move()
        {
            usleep(DELAY);

            switch(direction)
            {
                case UP:
                    Y++;
                    break;
                case LEFT:
                    X--;
                    break;
                case DOWN:
                    Y--;
                    break;
                case RIGHT:
                    X++;
                    break;
            }
        }

        // "Kills" either the ghost or Mecman, based on if the latter was invincible or not
        // when they touched each other
        virtual void kill() {};

        // Verifies if the Character is going to hit a wall
        /*bool goingToHitWall(Map map)
        {
            switch(direction)
            {
                case UP:
                    if (map.at(X,Y+1) == WALL)
                        return true;
                case LEFT:
                    if (map.at(X-1,Y) == WALL)
                        return true;
                case DOWN:
                    if (map.at(X,Y-1) == WALL)
                        return true;
                case RIGHT:
                    if (map.at(X+1,Y) == WALL)
                        return true;
            }

            return false;
        }*/

        virtual void changeDirection() {};

        // Getters/Setters
        int getX(){return X;}
        int getY() {return Y;}
        int getDirection() {return direction;}
        char getIcon() {return icon;}
        void setX(int X) {this->X = X;}
        void setY(int Y) {this->Y = Y;}
        void setDirection(int direction) {this->direction = direction;}
        void setIcon(char icon) {this->icon = icon;}
};