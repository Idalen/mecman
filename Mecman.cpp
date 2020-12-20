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

    void Mecman::move(Map* map){
        
        if(map->at(this->Y, this->X) == 'M')
            this->alive = FALSE;
        Character::move(map);
        if(map->at(this->Y, this->X) == 'M')
            this->alive = FALSE;
    }

    bool Mecman::isAlive(){
        return this->alive;
    }


