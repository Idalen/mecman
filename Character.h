#include "Map.h"
#include <unistd.h> //delay
#include <mutex>

#ifndef CHARACTER_H
#define CHARACTER_H

#define UP      0
#define LEFT    1
#define DOWN    2
#define RIGHT   3
#define DELAY   200000

class Character
{
    protected:
        int direction, X, Y;
        char icon;

    public:
    
        explicit Character(int Y, int X, Map* map, int direction, char icon);
        char move(Map* map, char last_icon);
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