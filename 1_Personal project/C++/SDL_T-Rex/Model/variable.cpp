#include "../Header/variable.h"

char                title[] = "T_REX";
int                 H_Floor = 70;
int                 WIDTH = 1000;
int                 HEIGHT = 400;
int                 posX0 = 0;
int                 posY0 = 50;
int                 yFloor = HEIGHT - H_Floor;
//loop
bool                running = true;
//vectors
std::vector<Entitie*>    entities;
std::vector<Floor*>      floors;
std::vector<T_REX*>      t_rexs;
std::vector<OBSTC*>      obstacles;