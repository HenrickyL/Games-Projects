#include <iostream>
#include "../Header/Obstacle.h"
#include "../Header/variable.h"
#include "../Header/T_rex.h"


OBSTC::OBSTC(Window &window, double x, double y, int type):
Entitie(window,x,y), _obs_type(type)
{  
    //verifico o tipo e organizo a posição
    generateType(type);
    _vy = 0;
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
}
//Tick
void OBSTC::tick(){
    if(!_pause){
       if((Window::getTime() - _initTime) == 1 && _status == -1 )start();
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
            if(this->intersect(t)){
                t->setDead(true); //para o dinossauro
                t->setStatus(-1);
                t->color("pink");
                _status = -1;
                if(_RNTest == false){ //se não tiver usando a rede neural
                    for(int j = 0; j < obstacles.size(); j++){ //Parar todo mundo
                        OBSTC *o = obstacles.at(i);
                        o->setStatus(-1);
                    }
                }
                
            }
        }
    }
}
void OBSTC::tickSpeedIncrementation(){
    if(_status != -1 && (Window::getTime()-_initTime)%10 == 0 && _vy<Spd_max){
        std::cout << "upSpeed!\n";
        //_vx *= 1.1; 
    }
}
//gerador de tipos
void OBSTC::generateType(int type){
    if(_obs_type == 1){ // cacto pequeno
        _w=OBS1_w;
        _h=OBS1_h;
    }else if(_obs_type == 2){ // cacto medio
        _w=OBS2_w;
        _h=OBS2_h;
    }else if(_obs_type == 3){ // cacto grande
        _w = OBS3_w;
        _h = OBS3_h;

    }else if(_obs_type == 4){ // passaro
        _w = OBS4_w;
        _h = OBS4_h;

    }
}