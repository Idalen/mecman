#include "Ghost.h"
#include <queue>
#include <vector>

typedef struct trio{
    int y; 
    int x;
    int last_direction;
    int first_direction;
};



void Ghost::changeDirection(Map* map){
    
    int mat[HEIGHT][WIDTH];

    trio pos = {.y = this->Y-1, .x = this->X, .last_direction = UP, .first_direction = UP};
    std::queue<trio> q;
    q.push(pos);

    pos = {.y = this->Y, .x = this->X-1, .last_direction = LEFT, .first_direction = LEFT};
    q.push(pos);

    pos = {.y = this->Y+1, .x = this->X, .last_direction = DOWN, .first_direction = DOWN};
    q.push(pos);

    pos = {.y = this->Y, .x = this->X+1, .last_direction = RIGHT, .first_direction = RIGHT};
    q.push(pos);

    while(!q.empty()){
        
        trio aux;
        pos = q.front();
        q.pop(); 

        aux.first_direction = pos.first_direction
        mat[pos.y][pos.x] = -1;

        if(pos.last_direction !=DOWN){
            aux = {.y = pos.y-1, .x = pos.x, .last_direction = UP};
            q.push(pos);
        }

        pos = {.y = pos.y, .x = pos.x-1, .last_direction = LEFT};
        q.push(pos);

        pos = {.y = pos.y+1, .x = pos.x, .last_direction = DOWN};
        q.push(pos);

        pos = {.y = pos.y, .x = pos.x+1, .last_direction = RIGHT};
        q.push(pos);


    }




    this->direction = direction;

}

void Ghost::move(Map* map, Mecman* mecman){
    
    if(map->at(this->Y, this->X) == 'C')
        mecman->kill();

    this->last_icon = Character::move(map, this->last_icon);
    
    if(map->at(this->Y, this->X) == 'C')
        mecman->kill();
}
