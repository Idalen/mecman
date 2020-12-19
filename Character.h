#include "Map.h"
#include <unistd.h> //delay

#ifndef CHARACTER_H
#define CHARACTER_H

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

        explicit Character(int Y, int X, Map* map, int direction, char icon);
        void move(Map* map);
        virtual void kill();
        virtual void changeDirection();
        int getX();
        int getY();
        int getDirection();
        char getIcon();
        void setX(int X);
        void setY(int Y);
        void setDirection(int direction);
        void setIcon(char icon);
};

#endif