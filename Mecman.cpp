#include "Mecman.h"

    void Mecman::kill()
    {
        this->alive = FALSE;
    }
    
    void Mecman::input(int ch)
    {
        switch(ch)
        {	
            case KEY_LEFT:				
                setDirection(LEFT);
                break;
            case KEY_RIGHT:				
                setDirection(RIGHT);
                break;
            case KEY_UP:				
                setDirection(UP);
                break;
            case KEY_DOWN:
                setDirection(DOWN);
                break;
        }
    }

    void Mecman::move(Map* map, std::mutex* write_read_m){
        
        write_read_m->lock();
        if(map->at(this->Y, this->X) == 'M')
            this->alive = FALSE;
        write_read_m->unlock();

        Character::move(map, write_read_m);

        write_read_m->lock();
        if(map->at(this->Y, this->X) == 'M')
            this->alive = FALSE;
        write_read_m->unlock();
    }

    bool Mecman::isAlive(){
        return this->alive;
    }


