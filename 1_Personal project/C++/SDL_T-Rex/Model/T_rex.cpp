//implementação
#include <iostream>
#include "../Header/T_rex.h"
#include "../Header/Floor.h"
#include "../Exec/main.cpp"
#include <vector>
template<typename Base, typename T>
inline bool instanceof(const T*) {
   return std::is_base_of<Base, T>::value;
}


    //variaveis staticas
//int T_REX::_ticks = 0;

//construtor e destrutor por omissão são da pai
T_REX::T_REX(Window &window, double x, double y): 
Entitie(window,x,y)
{   _type = "t_rex";
    _w=22;
    _h=30;
    this->status = -1; // em espera pra correr
    this->dead = false;
    this->color("red");
    _x0=x-_w, _y0=y-_h;
    _x = _x0, _y = _y0;
    std::cout<<"Dino criado!\n";
}


void T_REX::up(){
    if(status != -1 && status != 1){
        std::cout<<"Dino up\n";
        status = 1;
        _vy = 0.2; //impulso
    }
    
    
}
void T_REX::down(){
    if(status != -1 && status != 2){
        std::cout<<"Dino abaixa\n";
        status = 2;
    }
}
void T_REX::start(){
    std::cout << "start\n";
    status = 0;
}

void T_REX::tick(){
    //_ticks++;
    this->checkKey();
    //atualizo sua posição
    if(!dead && status != -1 && (_x+_w) < _width){
        
        if(Window::_ticks%10 ==0)_x+=_vx; // um tick de posição
        if(isFree(_y +_g - _vy)) _y += _g-_vy;
        //if(status == 1) _y -=_vy;
    }
    // aplico gravidade
    applyGravity();
    //Verifico o quanto correu
    howMuchRun();
    //converter status
}
//complemento do tick
void T_REX::howMuchRun(){
    if(this->status != -1 ){ //se não tiver começado
        this->run = this->_x - this->_x0;
        //std::cout<<"SCORE: "<<run<<"\n";
    }
}
void T_REX::applyGravity(){
    if(!dead && status < 1 ){
        _vy -= _g; 
    }if(isFree(_y+_g-_vy)){
        status = 0;
    }
}
void T_REX::checkKey(){
    SDL_Event event;
    if(SDL_PollEvent(&event) && event.type == SDL_KEYDOWN){
        if(event.key.keysym.sym == SDLK_SPACE && status == -1){
            this->start();
        }else if(event.key.keysym.sym == SDLK_DOWN){
            this->down();
        }else if(event.key.keysym.sym == SDLK_UP /*|| event.key.keysym.sym == SDLK_SPACE*/){
            this->up();
        }
    }else if(SDL_PollEvent(&event) && event.type == SDL_KEYUP){
        if(event.key.keysym.sym == SDLK_UP && status == 2){
            status = 0;
        }
    }
}
//end
void T_REX::render(){
    this->draw();
}

bool T_REX::isFree(int nextY){
    for(int i =0;i<floors.size();i++){
        Floor *f = floors.at(i);
        if(this->intersect(*f) ){
            return 0;
        }
    }return 1;
}