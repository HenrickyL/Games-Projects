#include <iostream>
#include "../Header/Floor.h"
#include "../Header/variable.h"



Floor::Floor(Window *window,double x, double y):
Entitie(window,x,y)
{   _type = "floor";
    _vx = Spd_Floor_OBS;
    _w = window->getWidth()/_div;
    _h = window->getHeight() - y; 
    //adicionar as listas
    entities.push_back(this);
    floors.push_back(this);
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
