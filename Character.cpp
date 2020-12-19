#include "Character.h"

Character::Character(int X, int Y, Map* map, int direction, char icon)
{
    this->icon = icon; 
    this->direction = direction;
    this->X = X;
    this->Y = Y;

    map->write(Y, X, icon);
}

void Character::move(Map* map)
{
    usleep(DELAY);

    map->write(this->Y, this->X, ' ');

    switch(direction)
    {
        case UP:
            this->Y--;
            break;
        case LEFT:
            this->X--;
            break;
        case DOWN:
            this->Y++;
            break;
        case RIGHT:
            this->X++;
            break;
    }

    map->write(this->Y, this->X, this->icon);
}

    
void Character::kill() {};
void Character::changeDirection() {};

        
int  Character::getX(){return X;}
int  Character::getY() {return Y;}
int  Character::getDirection() {return direction;}
char Character::getIcon() {return icon;}
void Character::setX(int X) {this->X = X;}
void Character::setY(int Y) {this->Y = Y;}
void Character::setDirection(int direction) {this->direction = direction;}
void Character::setIcon(char icon) {this->icon = icon;}
