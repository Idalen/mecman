#include <cstdlib>
#include "Ghost.cpp"

// Orange ghost
class Clyde: public Ghost
{

        // Uses Character constructor
        using Ghost::Ghost;
        
        // TODO
        // Clyde moves randomly
        void chase()
        {       
                /*while (goingToHitWall())
                        this->direction = rand()%4;*/
        }

        // TODO
        // Clyde goes to the bottom right corner while Mecman is invincible
        void scatter()
        {

        }
};