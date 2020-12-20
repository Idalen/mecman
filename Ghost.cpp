#include "Ghost.h"

void Ghost::changeDirection(){
    this -> direction =rand()%4;
}

void Ghost::kill()
{
}

void Ghost::move(Map* map, Mecman* mecman, std::mutex* write_read_m){
    
    write_read_m->lock();
    if(map->at(this->Y, this->X) == 'C')
        mecman->kill();
    write_read_m->unlock();

    Character::move(map, write_read_m);
    
    write_read_m->lock();
    if(map->at(this->Y, this->X) == 'C')
        mecman->kill();
    write_read_m->unlock();
}
