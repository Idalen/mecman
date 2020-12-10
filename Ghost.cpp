#include "Character.cpp"

class Ghost: public Character
{
    public:

        // Uses Character constructor
        using Character::Character;

        // Determines the pathing of the Ghost while Pacman is not invincible
        virtual void chase() {};

        // Determines the pathing of the Ghost while Pacman is invincible
        virtual void scatter() {};

        // TODO
        // "Kills" the Ghost. Happens when Pacman touches the ghost while invincible
        void kill()
        {

        }
};