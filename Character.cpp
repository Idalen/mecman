#include "Character.h"

Character::Character(int X, int Y, int direction)
{
    this->direction = direction;
    this->X = X;
    this->Y = Y;
}

void Character::move()
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
