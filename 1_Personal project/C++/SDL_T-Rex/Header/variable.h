#ifndef VARIABLE_H
#define VARIABLE_H


#include <vector>
#include "Entitie.h"
#include "Floor.h"
#include "T_rex.h"
#include "Obstacle.h"
#include <string>

//std::vector<ENTITIE>    Entities;
//Variáveis
extern char                     title[];// = "T_REX";
extern int                      H_Floor;// = 70;
extern int 				    	WIDTH;// = 1000;
extern int						HEIGHT;// = 400;
extern int                      ticks;// = 0;
extern int   	                posX0;// = 0;
extern int						posY0;// = 50;
extern int                      yFloor;// = HEIGHT - H_Floor;
//loop
extern bool                     running;// = true;
//vector
extern std::vector<Entitie*>    entities;
extern std::vector<Floor*>      floors;
extern std::vector<T_REX*>      t_rexs;
extern std::vector<OBSTC*>      obstacles;





#endif
