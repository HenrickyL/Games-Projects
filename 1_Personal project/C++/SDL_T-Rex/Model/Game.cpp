//tudo relacionado ao game

#include <iostream>
#include <random>
#include "../Header/Game.h"

Game::Game(bool RN):
_RN(RN)
{
    //inicalizar variaveis
    init();
    //geradores
    generateWindow();
    generateFloor();
    generateObstacle();
    generateT_rex();
}
Game::Game()
{
    //inicalizar variaveis
    init();
}

Game::~Game(){
    destroyWindow();
    destroyFloor();
    destroyObstacle();
    destroyT_rex();
}


// TICK e RENDER ////////////////////////////////////////////////////////////////
void Game::tick(){
    if(!_window->_pause){
        //tick das entidades

        //calculadores ou verificadores
    
    }
} 
void Game::render(){ //ordem de renderização importa
    //render de Floor
    renderFloor();
    //render de obstacles
    renderObstacle();
    //render de T_rex
    renderT_rex();
    //textos
}
////////////////////////////////////////////////////////////////////////////////////
void Game::start(){
    _runing = true;
    std::cout << "<Game Start!>\n";
    //loop
    while(_runing){

    }stop();
} 
void Game::pause(){
    _window->_pause = true;

}
void Game::stop(){
    std::cout << "<Game Stop!>\n";
    _runing = false;

} 

//Inicializador /////////////////////////////////////////////////////////////////
 void Game::init(){
     _qtdDino = QTD_DINOS;
     _qtdObstacles = QTD_OBSTACLES;
     _qtdFloor; // * com base na quantidade de obstaculos
 }
//Geradores:
void Game::generateWindow(){
    _window = new Window(title, WIDTH,HEIGHT);
    if(_window == nullptr) std::cerr << "<Falha em criar janela!>\n";
}
void Game::generateFloor(){
    int pos=0;
    for(int i=0;i < _qtdFloor;i++){
        Floor *f = new Floor(*_window,pos,yFloor);
        pos+= _window->getWidth()/f->getDiv();
    }
}
void Game::generateT_rex(){
    int qtd;
    if(_RN){
        qtd = _qtdDino;
    }else{
        qtd =1;
    }
    for(int i = 0 ; i < qtd ; i++){
        T_REX *t = new T_REX(*_window,50,HEIGHT-H_Floor);
    }
}
void Game::generateObstacle(){ 
    _obsPositions = new int[_qtdObstacles];
    randomGenerate(_obsPositions, _qtdObstacles, WIDTH,_obsMinDist);
    srand (time(NULL)); //semente
    int type = rand() % 4 + 1; // de 1 a 4
    int  y = yFloor;
    if(type == 4){
        
    }

    for(int i =0; i< QTD_OBSTACLES; i++){
        OBSTC *o = new OBSTC(*_window,_obsPositions[i],yFloor, type);
    }
}
void Game::randomGenerate(int *pos, int len, int initPos, int distMin){
    //gerador aleatório(tipo) de obstáculos com distância minima entre eles
    srand (time(NULL)); //semente
    for(int i = 0; i < len ; i++){
        pos[i] = rand() % (distMin) + initPos;
        if(pos[i]>initPos && pos[i]<=initPos+distMin){
        	
        	initPos+=distMin;

        }else{

        	i--;
        }
    }

}
//DESTRUTOTES ////////////////////////////////////////////////////////////////////
void Game::destroyWindow(){
    delete _window;
}
void Game::destroyFloor(){
    for(int i = 0; i< floors.size(); i++){
        delete floors.at(i);
    }

}
void Game::destroyT_rex(){
    for(int i = 0; i< t_rexs.size(); i++){
        delete t_rexs.at(i);
    }
}
void Game::destroyObstacle(){
    for(int i = 0; i< obstacles.size(); i++){
        delete obstacles.at(i);
    }
} 


//Renderizadores: ///////////////////////////////////////////////////////////////
void Game::renderT_rex(){
    for(int i=0;i<t_rexs.size();i++){
        t_rexs.at(i)->render();
    }
}
void Game::renderFloor(){
    for(int i=0;i<floors.size();i++){
        floors.at(i)->render();
    }
}
void Game::renderObstacle(){
    for(int i=0;i<obstacles.size();i++){
        obstacles.at(i)->render();
    }

}
//calculadores: //////////////////////////////////////////////////////////////////////
void Game::CalcScore(){

}