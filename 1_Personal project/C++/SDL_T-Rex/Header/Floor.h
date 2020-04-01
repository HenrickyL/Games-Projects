#ifndef FLOOR_H
#define FLOOR_H

#include "Entitie.h"
#include <vector>

class Floor : public Entitie{
public:
    Floor(Window &window,double x, double y); 
    
    
    //métodos
    void render();
    void tick();
    
    //variaveis
private:
    double  _vx = 0.1;//0.1;
    int     _div = 16; // numero de divisões em tela
    bool    _start = false;
    
    //métodos privados
    void incrementVx(); // incrementar velocidade
    void start();
    void pollEvents();
public:
    //getter e setter
    bool getStart()const{return _start;}
    void setStart(bool start){_start = start;}
     

};


#endif