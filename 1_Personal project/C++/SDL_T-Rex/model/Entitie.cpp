//implementação
#include <iostream>
#include "Entitie.h"
#include "Sprite.h"

ENTITIE::ENTITIE(double x, double y){ //construtor
    //std::cout<<"Entidade Criada\n";
    this->x0 = x;
    this->y0 = y;
    this->x = x;
    this->y = y;
    //sprite
}
ENTITIE::~ENTITIE(){
    //std::cout<<"Entidade Destruida\n";
}
//métodos getter e setter

double ENTITIE::getX(){
    return this->x;
}void ENTITIE::setX(double x){
    this->x = x;
}
double ENTITIE::getY(){
    return this->y;
}void ENTITIE::setY(double y){
    this->y = y;
}

