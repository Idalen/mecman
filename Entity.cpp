
class Entity
{
    public:
        explicit Entity(int X, int Y)
        {
            this->X = X;
            this->X = Y;
        }

        // TODO
        // Inserts the Entity into the game at the specified position
        void insert(int X, int Y)
        {

        }

        // TODO
        // Removes the Entity from the game
        void remove()
        {

        }

        // Determines if this Entity is touching another Entity
        bool touching(Entity E)
        {
            return X == E.getX() && Y == E.getY();
        }

        // Getters/Setters
        int getX(){return X;}
        int getY() {return Y;}
        void setX(int X) {this->X = X;}
        void setY(int Y) {this->Y = Y;}

    protected:
        int X, Y;
};