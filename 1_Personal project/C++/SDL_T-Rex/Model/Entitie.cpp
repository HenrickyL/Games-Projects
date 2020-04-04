//implementação
#include <iostream>
#include "../Header/Entitie.h"
#include "../Header/Sprite.h"

Entitie::Entitie(Window *window , double x, double y):
Rect(window,x,y)
{
    _w = 40;
    _h = 30;
    _r=255,_g=255,_b=0;
}
Entitie::Entitie(Window *window ,int w, int h, double x, double y):
Rect(window,w,h,x,y)
{ 
    _r=255,_g=255,_b=0;
}
void Entitie::tick(){
    
}
void Entitie::render(){
    this->draw();
}



//métodos getter e setter

double Entitie::getX(){
    return _x;
}void Entitie::setX(double x){
    this->_x = x;
}
double Entitie::getY(){
    return this->_y;
}void Entitie::setY(double y){
    this->_y = y;
}

