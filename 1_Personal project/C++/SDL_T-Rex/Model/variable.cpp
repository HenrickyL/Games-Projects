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
    //Colors
    std::map<std::string, SDL_Color>colors;
    //Fonts
    std::map<std::string,TTF_Font*>fonts;

    //Game Constants
    double                  Spd_Floor_OBS = 0.1; //velociade dos obstaculos e chao
    double                  Spd_max = 0.6;
    int                     QTD_OBSTACLES = 200;
    int                     QTD_DINOS = 50; //Rede neural

    //Entities dimensions
    int                     DINO_w = 35;
    int                     DINO_h = 50;

    int                     OBS1_w = 20;
    int                     OBS1_h = 25;
    
    int                     OBS2_w = 27;
    int                     OBS2_h = 35;
    
    int                     OBS3_w = 33;
    int                     OBS3_h = 40;
    
    int                     OBS4_w = 40;
    int                     OBS4_h = 20;



