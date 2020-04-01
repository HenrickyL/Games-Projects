#include <iostream>
#include "../Header/Obstacle.h"
#include "../Header/variable.h"
#include "../Header/T_rex.h"


OBSTC::OBSTC(Window &window, double x, double y, int type):
Entitie(window,x,y), _obs_type(type)
{  
    //verifico o tipo e organizo a posição
    generateType(type);
    _x = x - _w;
    _y = y - _h;
    this->color("green");
    std::cout << "OBSTC::Create!\n";
    //adicionando as listas
    obstacles.push_back(this);
    entities.push_back(this);
    

}
//start
void OBSTC::start(){
    std::cout << "OBST::start!\n";
    _status = 0;
    _initTime = Window::getTime();
}
//Tick
void OBSTC::tick(){
    if(!_pause){
        tickSpeedIncrementation();
        tickPosIncrementation();
        tickColid();
    }
}
//Render
void OBSTC::render(){
    this->draw();
}

//funções auxiliares da função tick
void OBSTC::tickPosIncrementation(){
    if(_status != -1){
        _x -= _vx;
    }
}
void OBSTC::tickColid(){
    if(_status != -1 && !t_rexs.empty()){
        for(int i = 0; i< t_rexs.size();i++){
            T_REX *t = t_rexs.at(i);
            if(this->intersect(*t)){
                t->setDead(true); //para o dinossauro
                t->setStatus(-1);
                _status = -1;
                if(!_RNTest){ //se não tiver usando a rede neural
                    for(int j = 0; j < entities.size(); j++){ //Parar todo mundo
                        OBSTC *o = obstacles.at(i);
                        o->setStatus(-1);
                    }
                }
                
            }
        }
    }
}
void OBSTC::tickSpeedIncrementation(){
    if(_status != -1 && (Window::getTime()-_initTime)%10 ==0){
        _vx *= 1.1; 
    }
}
//gerador de tipos
void OBSTC::generateType(int type){
    if(_obs_type == 1){
        _w=25;
        _h=30;
    }else if(_obs_type == 2){
        _w=30;
        _h=40;
    }
}