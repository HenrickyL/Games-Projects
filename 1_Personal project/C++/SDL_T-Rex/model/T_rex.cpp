//implementação
#include <iostream>
#include "T_rex.h"
#include <vector>
#include <SDL/SDL.h>
#include "SDL/SDL_opengl.h"
#include "variable.h"


//construtor e destrutor por omissão são da pai
T_REX::T_REX(double x, double y) : ENTITIE(x, y){
    this->status = -1; // em espera pra correr
    this->dead = false;
    std::cout<<"Dino criado!\n";
}
T_REX::~T_REX(){
    std::cout<<"Trex destruido\n";
}
void T_REX::up(){
    std::cout<<"Dino up\n";
    if(status != 1 && vy != 1){
        status = 1;
        vy*= 3.5; //impulso
    }
    
    
}
void T_REX::down(){
    std::cout<<"Dino abaixa\n";
}
void T_REX::start(){
    status = 0;
}

void T_REX::tick(){
    //atualizo sua posição
    if(!dead && status != -1){
        x*=vx; // um tick de posição
        y*=vy;
    }
    // aplico gravidade
    applyGravity();
    //Verifico o quanto correu
    howMuchRun();
    //converter status
    if(vx == 1){ // se pular muda status e vy, logo quando voltar a 1 ele fica normal
        status = 0;
    }
}
//complemento do tick
void T_REX::howMuchRun(){
    if(this->status != -1 ){ //se não tiver começado
        this->run = this->x - this->x0;
    }
}
void T_REX::applyGravity(){
    if(!dead && status != -1 && vy >1){
        vy*=0.8; // vou desgastando a velocidade
        if(vy<1) vy = 1;
    }
}
//end
void T_REX::render(){
    glPointSize(10);
    glBegin(GL_POINTS);
		glColor4ub(255,0,0,255);
		glVertex2i(this->x,this->y);
	glEnd();
}
