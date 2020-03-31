#ifndef VARIABLE_H
#define VARIABLE_H


#include <vector>
#include "Entitie.h"
#include "Floor.h"
#include <string>


//std::vector<ENTITIE>    Entities;
//Variáveis
char                    title[] = "T_REX";
int                     H_Floor = 70;
int 					WIDTH = 1000;
int						HEIGHT = 400;
int                     ticks = 0;
int 	                posX0 = 0;
int						posY0 = 50;
int                     yFloor = HEIGHT - H_Floor;
//loop
bool                    running = true;
std::vector<Entitie*>   entities;
std::vector<Floor*>     floors;





#endif
