//implementação
#include <iostream>
#include "../Header/T_rex.h"
#include "../Header/Floor.h"
#include "../Header/variable.h"
#include <vector>
/*
template<typename Base, typename T>
inline bool instanceof(const T*) {
   return std::is_base_of<Base, T>::value;
}*/


    //variaveis staticas


//construtor e destrutor por omissão são da pai
T_REX::T_REX(Window &window, double x, double y): 
Entitie(window,x,y)
{
    _type = "t_rex";
    _vy = _impulse;
    _w=DINO_w;
    _h=DINO_h;
    this->status = -1; // em espera pra correr
    this->_dead = false;
    this->color("black");
    int _x0=x-_w, _y0=y-_h;
    _x = _x0, _y = _y0;
    _vx = 0.1;
    //adicionando aos listas
    t_rexs.push_back(this);
    entities.push_back(this);
    std::cout<<"Dino criado!\n";
}


void T_REX::up(){
    if(status != -1 && status != 1){
        std::cout<<"Dino up\n";
        status = 1;
        _vy = _impulse; //impulso
        color("yellow");
    }
    
    
}
void T_REX::down(){
    if(status != -1 && status != 2){
        std::cout<<"Dino abaixa\n";
        status = 2;
        color("green");
    }
}
void T_REX::start(){
    std::cout << "TREX::start!\n";
    status = 0;
    color("red");
}

void T_REX::tick(){
    if(!_pause){
        //if( (Window::getTime() - _initTime) == 1 && status == -1) start();
       
        // aplico gravidade
        tickApplyGravity();
        //atualizo sua posição
        tickPosIncrementation();
        tickCheckKey();
        
    }
    
}
//complemento do tick
/*void T_REX::howMuchRun(){
    if(this->status != -1 ){ //se não tiver começado
        this->run = this->_x - this->_x0;
        //std::cout<<"SCORE: "<<run<<"\n";
    }
}*/
void T_REX::tickPosIncrementation(){
    if(!_dead && status != -1 && (_x+_w) < _width && (_y+_h)<_height){
            //X
            _x+=_vx; // um tick de posição
            //_y +=_g - _vy;
            //Y
            if(isFree(_y + _g -_vy)){
                _y += _g - _vy;
            }    
            else if(status != 0){
                status = 0;
                color("red");
            }
    }
}
void T_REX::tickApplyGravity(){
    if(!_dead && status != -1 && _ticks%10 == 0){
        _vy -= _g; 
    }
}
void T_REX::tickCheckKey(){
    SDL_Event event;
   // if(SDL_PollEvent(&event) && event.type ==SDL_QUIT) setClosed(true);
    if(SDL_PollEvent(&event) && event.type == SDL_KEYDOWN){
        if(status == -1) this->start();
        if(event.key.keysym.sym == SDLK_DOWN){
            std::cout << "Dino : up!\n";
            this->down();
        }else if(event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_SPACE){
            this->up();
            std::cout << "Dino : Down!\n";
        }
        
    }if(SDL_PollEvent(&event) && event.type == SDL_KEYUP){
        if(event.key.keysym.sym == SDLK_UP && status == 2){
            status = 0;
        }
    }
}
//end
void T_REX::render(){
    this->draw();
}

bool T_REX::isFree(double nextY){
    if(!floors.empty()){
        double backY = this->_y;
        this->_y = nextY;
    
        for(int i =0;i<floors.size();i++){
            Floor *f = floors.at(i);
            if(this->intersect(f) ){
                this->_y = backY;
                return 0;
                
            }
        }
    this->_y = backY;
    }        
    return 1;
}