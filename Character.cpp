#include "Character.h"

Character::Character(int Y, int X, Map* map, int direction, char icon)
{
    this->icon = icon; 
    this->direction = direction;
    this->X = X;
    this->Y = Y;

    map->write(Y, X, icon); 
}

char Character::move(Map* map, char last_icon)
{   

    map->write(this->Y, this->X, last_icon);
    

    switch(direction)
    {
        case UP:
            if(map->at(this->Y-1, this->X) != '#')    
                this->Y--;
            break;
        case LEFT:
            if(map->at(this->Y, this->X-1) != '#')
                this->X--;
            break;
        case DOWN:
            if(map->at(this->Y+1, this->X) != '#')
                this->Y++;
            break;
        case RIGHT:
            if(map->at(this->Y, this->X+1) != '#')
                this->X++;
            break;

    }

    last_icon = map->at(this->Y, this->X); 
    map->write(this->Y, this->X, this->icon);

    return last_icon;

}

int  Character::getX(){return X;}
int  Character::getY() {return Y;}
int  Character::getDirection() {return direction;}
char Character::getIcon() {return icon;}
void Character::setX(int X) {this->X = X;}
void Character::setY(int Y) {this->Y = Y;}
void Character::setDirection(int direction) {this->direction = direction;}
void Character::setIcon(char icon) {this->icon = icon;}
