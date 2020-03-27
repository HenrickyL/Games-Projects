#ifndef FLOOR_H
#define FLOOR_H

#include "Entitie.h"

class Floor : public ENTITIE{
public:
    Floor(double x, double y, double w, double h);
    //~Floor();
    
    //métodos
    void render();
    void tick();
};


#endif