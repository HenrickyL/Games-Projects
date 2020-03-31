#include <iostream>
#include "../Header/Floor.h"
#include <vector>



Floor::Floor(Window &window,double x, double y):
Entitie(window,x,y)
{   _w = window.getWidth()/_div;
    _h = window.getHeight() - y; 
}

void Floor::render(){
    this->draw();
}
void Floor::tick(){
    pollEvents(); //start
    if(_start){ //mover todos os quadrados
        _x-=_vx;
    }
}
void Floor::start(){
    _start = true;
}
 void Floor::pollEvents(){
     SDL_Event event;
     if(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT) setClosed(true);
        if(event.type == SDL_KEYDOWN){
             if(event.key.keysym.sym == SDLK_SPACE){
                 start();
             }
        }
     }
}
