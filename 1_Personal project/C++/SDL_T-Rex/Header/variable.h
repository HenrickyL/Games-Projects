#ifndef VARIABLE_H
#define VARIABLE_H



#include "Entitie.h"
#include "Floor.h"
#include "T_rex.h"
#include "Obstacle.h"
#include <string>
#include <vector>


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

    //Game Constants
    extern double                  Spd_Floor_OBS; //velociade dos obstaculos e chao
    extern double                  Spd_max;
    extern int                     QTD_OBSTACLES;
    extern int                     QTD_DINOS; //Rede neural

    //Entities dimensions
    extern int                     DINO_w;
    extern int                     DINO_h;

    extern int                     OBS1_w;
    extern int                     OBS1_h;
    
    extern int                     OBS2_w;
    extern int                     OBS2_h;
    
    extern int                     OBS3_w;
    extern int                     OBS3_h;
    
    extern int                     OBS4_w;
    extern int                     OBS4_h;







#endif
