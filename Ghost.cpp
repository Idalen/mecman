#include "Ghost.h"

void Ghost::changeDirection(){
    this -> direction =rand()%4;
}

void Ghost::kill()
{
}

void Ghost::move(Map* map, Mecman* mecman){
    
    if(map->at(this->Y, this->X) == 'C')
        mecman->kill();
    Character::move(map);
    if(map->at(this->Y, this->X) == 'C')
        mecman->kill();
}
