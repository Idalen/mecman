#include "Ghost.h"

class Ghost: public Character
{
    public:

        // Uses Character constructor
        explicit Ghost(int Y, int X, Map* map) : Character(Y, X, map, RIGHT, 'M'){};

        void changeDirection(){
            this -> direction =rand()%4;
        }
        
        // Determines the pathing of the Ghost while Pacman is not invincible
        virtual void chase(Character character) {};

        // Determines the pathing of the Ghost while Pacman is invincible
        virtual void scatter() {};

        // TODO
        // "Kills" the Ghost. Happens when Pacman touches the ghost while invincible
        void kill()
        {

        }
        
        void move(Map* map, Mecman* mecman){
            
            if(map->at(this->Y, this->X) == 'C')
                mecman->kill();

            Character::move(map);

            if(map->at(this->Y, this->X) == 'C')
                mecman->kill();
        }
};
