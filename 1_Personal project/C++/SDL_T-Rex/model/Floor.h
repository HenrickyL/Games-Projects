#ifndef FLOOR_H
#define FLOOR_H

#include "Entitie.h"

class Floor : public ENTITIE{
public:
    Floor();
    ~Floor();
    
    //métodos
    void render();
    void tick();
};


#endif