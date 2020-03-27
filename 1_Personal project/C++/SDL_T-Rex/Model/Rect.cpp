#include <iostream>
#include "../Header/Rect.h"

Rect::Rect(const Window &window, double x, double y):
Window(window),_x(x),_y(y)
{  
    _w = 20;
    _h = 20;
}
Rect::Rect(const Window &window, int w, int h, double x, double y):
Window(window), _w(w),_h(h),_x(x),_y(y)
{
}
//sobrecarga
Rect::Rect(const Window &window, int w, int h, double x, double y, int r, int g, int b, int a):
    Window(window), _w(w),_h(h),_x(x),_y(y), _r(r),_g(g),_b(b),_a(a)
{ 
}
void Rect::draw() const{
    SDL_Rect rect;
    rect.w = _w;
    rect.h = _h;
    rect.x = _x;
    rect.y = _y;

    SDL_SetRenderDrawColor(_renderer,_r,_g,_b,_a);
    SDL_RenderFillRect(_renderer,&rect);
}
void Rect::pollEvents(){
    //crio um evento
    SDL_Event event;
    if(SDL_PollEvent(&event)){ //está ocorrendo algum evento?
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