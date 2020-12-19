#include "Map.h"

char Map::at(int y, int x) {return this->map[y][x];}
void Map::write(int y, int x, char ch) {this->map[y][x] = ch;}
