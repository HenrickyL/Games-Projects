#include <iostream>
#include "Rect.h"




Rect::Rect(Window *window, double x, double y):
Window(*window),_x(x),_y(y),_window(window)
{  
    _w=30;
    _h=30;
}
Rect::Rect(Window *window, double x, double y, int border):
Window(*window),_x(x),_y(y), _border(border),_window(window)
{  
    _w=30;
    _h=30;
}
Rect::Rect(Window *window, int w, int h, double x, double y):
Window(*window),_x(x),_y(y),_window(window)
{
    _w=w;
    _h=h;
}
//sobrecarga
Rect::Rect(Window *window, int w, int h, double x, double y, int r, int g, int b, int a):
    Window(*window), _x(x),_y(y), _r(r),_g(g),_b(b),_a(a),_window(window)
{ 
    _w=w;
    _h=h;
}



void Rect::draw() const{
    
    SDL_Rect rect;
    rect.w = _w-_border-1;
    rect.h = _h-_border-1;
    rect.x = _x + _border;
    rect.y = _y + _border;
    SDL_Rect line;
    line.w = _w;
    line.h = _h;
    line.x = _x;
    line.y = _y;
    SDL_SetRenderDrawColor(_renderer,0,0,0,255);
    SDL_RenderFillRect(_renderer,&line);
    SDL_SetRenderDrawColor(_renderer,_r,_g,_b,_a);
    SDL_RenderFillRect(_renderer,&rect);
}
void Rect::keyEvents(){//está ocorrendo algum evento?
    //crio um evento
    pollEvents();
    SDL_Event event;
    if(SDL_PollEvent(&event)){
        //if(event.type == SDL_QUIT) setClosed(true);
        if(event.type == SDL_KEYDOWN){
            
            switch (event.key.keysym.sym){
                    case SDLK_UP:
                        _y -= 10;
                        break;
                    case SDLK_DOWN:
                        _y += 10;
                        break;
                    case SDLK_LEFT:
                        _x -= 10;
                        break;
                    case SDLK_RIGHT:
                        _x += 10;
                        break;    
                    default:
                    break;
                }
        }
         
    }
}
//controle de cor
void Rect::color(std::string cor){
    
    if(cor == "blue"){
        _r=0,_g=0,_b=255;
    }else if(cor == "red"){
        _r=255,_g=0,_b=0;
    }else if(cor == "white"){
        _r=255,_g=255,_b=255;
    }else if(cor == "yellow"){
        _r=255,_g=255,_b=0;
    }else if(cor == "black"){
        _r=0,_g=0,_b=0;
    }else if(cor == "green"){
        _r=0,_g=255,_b=0;
    }else if(cor == "pink"){
        _r=255,_g=182,_b=193;
    }else if(cor == "gray"){
        _r=128,_g=128,_b=128;
    }else{
        std::cout<<"Cor Indefinido!\n";
    }
}
void Rect::color(int r, int g, int b){
    _r=r,_g=g,_b=b;
}
void Rect::alpha(int a){
    _a=a;
}
bool Rect::intersect(Rect *B){
    //interação de retangulo A com B
    int Ax0 = this->_x, Ay0 = this->_y;
    int Ax = this->_x+this->_w,Ay = this->_y+this->_h;
    int Bx0 = B->_x, By0 = B->_y;
    int Bx = B->_x+B->_w,By = B->_y+B->_h;    
    if(
        Ax >= Bx0 && Ax0 <= Bx && Ay >= By0 && Ay0 <= By   
        ) return 1;
    else return 0;
}


std::string Rect::getColorStr(){
    if(_r==0 && _g==0 &&_b==255){
        return "blue";
    }else if(_r==255 && _g==0 &&_b==0){
        return "red";
    }else if(_r==255 && _g==255 &&_b==255){
        return "white";
    }else if(_r==255 && _g==0 &&_b==0){
        _r=255,_g=255,_b=0;
        return "yellow";
    }else if(_r==0 && _g==0 &&_b==0){
        return "black";
    }else if(_r==0 && _g==255 &&_b==0){
        return "green";
    }else if(_r==255 && _g==182 &&_b==193){
        return "pink";
    }else{
        return "other";
    }
}