#ifndef FLOOR_H
#define FLOOR_H

#include "Entitie.h"
#include <vector>

class Floor : public Entitie{
public:
    Floor(Window *window,double x, double y); 
    
    
    //métodos
    void render();
    void tick();
    
    //variaveis
private:
    double  _vx;
    int     _div = 16; // numero de divisões em tela ou t
    bool    _start = false;
    
    //métodos privados
    void incrementVx(); // incrementar velocidade
    void start();
    void pollEvents();
public:
    //getter e setter
    bool getStart()const{return _start;}
    void setStart(bool start){_start = start;}
    int getDiv(){return _div;}
     

};


#endif