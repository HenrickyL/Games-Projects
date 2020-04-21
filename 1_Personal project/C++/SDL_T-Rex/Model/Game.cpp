//tudo relacionado ao game

#include <iostream>
#include <random>
#include "../Header/Game.h"
///////////////////// interfaceof
        //USO:  instanceof<CLASS>(OBJECT)
template<typename Base, typename T>
inline bool instanceof(const T*) {
   return std::is_base_of<Base, T>::value;
}

////////////////////




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
    generateUI();
    std::cout << "<GAME :: Create!>\n";
}
Game::Game()
{
    //inicalizar variaveis
    init();
     //geradores
    generateColors();
    generateWindow();
    generateFloor();
    generateT_rex();
    generateUI();
    //generateObstacle();
    
    std::cout << "<GAME :: Create!>\n";
}

Game::~Game(){
    destroyFloor();
    destroyObstacle();
    destroyT_rex();
    destroyUI();
    destroyWindow();
    //encerrar o TTF
    TTF_Quit();
}












// TICK e RENDER ////////////////////////////////////////////////////////////////
void Game::tick(){
    
    if(!_window->_pause){
        //tick das entidades
        tickEntities();
        //calculadores ou verificadores
        tickCalcScore();
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
    renderScore();
}














////////////////////////////////////////////////////////////////////////////////////
void Game::start(){
    _runing = true;
    while(_runing){
        this->keyEvents();
        //ticks
        this->tick();
        //renders
        this->render();
        //limpar tela
        _window->clear();

    }
} 
void Game::pause(){
    if(_window->_pause) _window->_pause = false;
    else _window->_pause = true;

}
void Game::stop(){
    std::cout << "<Game Stop!>\n";
    _runing = false;
    Window::setClosed(true); //fecha janela

} 

//Inicializador /////////////////////////////////////////////////////////////////
 void Game::init(){
     //inicaliar TTF
     if(TTF_Init() == -1){
         std::cerr << "<Erro ao inicializar TTF!>\n";
     }
     //inicalizar variaveis
     _qtdDino = QTD_DINOS;
     _qtdObstacles = QTD_OBSTACLES;
     _qtdFloor; // * com base na quantidade de obstaculos
     
 }
 void Game::initStart(){
    _start = true; // para a verificações de keys
    //startar o dino e todos os outros
        
    int i;
    if(!floors.empty()){
        //startar Floor
        for(i=0;i<floors.size();i++){
            floors.at(i)->setStart(true);
        }
    }
    if(!obstacles.empty()){
        //startar Obstacles
        for(i=0;i<obstacles.size();i++){
            obstacles.at(i)->setStart(true);
        }
    }
    if(!t_rexs.empty()){
        //startar Dino
        for(i=0;i<t_rexs.size();i++){
            t_rexs.at(i)->start(); // status -1 é inativo
        }
    }
    std::cout << "<Game Start!>\n";
 }
//Geradores:
void Game::generateWindow(){
    _window = new Window(title, WIDTH,HEIGHT);
    _window->color("white");
    if(_window == nullptr) std::cerr << "<Falha em criar janela!>\n";
    else std::cerr << "<GAME:: Create Window!>\n";
}
void Game::generateFloor(){
    int pos=0;
    for(int i=0;i < _qtdFloor;i++){
        Floor *f = new Floor(_window,pos,yFloor);
        pos+= _window->getWidth()/f->getDiv()-1;
    }
    if(floors.empty()){
        std::cerr << "<Falha ao Criar o Chão!>\n";
    }else std::cerr << "<GAME:: Create Floor!>\n";
}
void Game::generateT_rex(){
    int qtd;
    if(_RN){
        qtd = _qtdDino;
    }else{
        qtd =1;
    }
    for(int i = 0 ; i < qtd ; i++){
        T_REX *t = new T_REX(_window,50,HEIGHT-H_Floor-100);
    }
    if(t_rexs.empty()){
        std::cerr << "<Falha ao Criar o(s) Dinossauro(s)!>\n";
    }else std::cerr << "<GAME:: Create T_REX!>\n";
}
void Game::generateObstacle(){ 
    _obsPositions = new int[_qtdObstacles];
    randomGenerate(_obsPositions, _qtdObstacles, WIDTH,_obsMinDist);
    srand (time(NULL)); //semente
    int type = rand() % 4 + 1; // de 1 a 4
    int  y = yFloor;
    if(type == 4){//colocar nas posições adequadas 
        
    }

    for(int i =0; i< QTD_OBSTACLES; i++){
        OBSTC *o = new OBSTC(_window,_obsPositions[i],yFloor, type);
    }
    //verificar de erro
    if(obstacles.empty()){
        std::cerr << "<Falha ao Criar Obstaculos!>\n";
    }else std::cerr << "<GAME:: Create Window!>\n";

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
//gerar as UIs
void Game::generateUI(){
    _font = new Text();
    _font->addFont(20);
    _scoreUI = new UILabel(_window,200, 100, "TextSprite", "arial", "black");
    //UILabel(_window,WIDTH,HEIGHT);
    if(_scoreUI == nullptr){
        std::cerr << "Falha ao gerar ScoreUI!\n";
    }else{
        std::cerr << "UI Criada!\n";
    }
    
}

//gerador de cores
void Game::generateColors(){
    std::cerr << "<Cores Criadas!>";
    colors["white"] = {255,255,255};
    colors["black"] = {0,0,0};
    colors["blue"] = {0,0,255};
    colors["red"] = {255,0,0};
    colors["green"] = {0,255,0};
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
void Game::destroyUI(){
    delete _font;
    delete _scoreUI;
}
//Atualizadores /////////////////////////////////////////////////////////////////
void Game::tickEntities(){
    int i;
    for(i=0;i<t_rexs.size();i++){
        t_rexs.at(i)->tick();
    }
}
void Game::tickCalcScore(){
    _score = t_rexs.at(0)->getX() - floors.at(0)->getX();
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
    if(!obstacles.empty()){
        for(int i=0;i<obstacles.size();i++){
            obstacles.at(i)->render();
        }
    }
}

void Game::renderScore(){
    if(_scoreUI != nullptr){
        std::string str = "";
	    str += std::to_string(_score);
        _scoreUI->setLabelText(str);
        _scoreUI->render();
    }
    
}

//KeyEvents ///////////////////////////////////////
void Game::keyEvents(){
    
    //eventos
    SDL_Event event;
    if(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT){
            this->stop();
        }
        if(event.type == SDL_KEYDOWN){
            if(!_start && event.key.keysym.sym == SDLK_SPACE){
                this->initStart();
            }else if(_start){
                switch (event.key.keysym.sym){
                case SDLK_ESCAPE: //ESQ
                    this->pause();
                    break;
                case SDLK_UP:
                    if(!_RN){
                        t_rexs.at(0)->up();
                    }
                    break;
                case SDLK_SPACE:
                    if(!_RN){
                        t_rexs.at(0)->up();
                    }
                    break;
                case SDLK_DOWN:
                    if(!_RN){
                        t_rexs.at(0)->down();
                    }
                    break;
                default:
                    break;
                }
            }
        }
    }
    
}



/*


    for(i =0;i<entities.size();i++){
        //o método tick so deve ocorrer se a entidade estiver viva, logo retiro ele o entities
        Entitie *e = entities.at(i);
        e->tick(); 
        /*if(instanceof<T_REX>(e)){
            for(i=0;i<t_rexs.size();i++){
                T_REX *t = t_rexs.at(i);
                //Verificar se o Dinossauro morreu para retirar
                if(e == t && t->isDead()){
                    //troco o elemento com o ultimo
                    Entitie *aux = entities.at(entities.size()-1);
                    entities.at(entities.size()-1) = entities.at(i);
                    entities.at(i) = aux;
                    //salvo seu score
                    t->setRun(t->getX() - floors.at(0)->getX());
                    //retiro o ultimo
                    entities.pop_back();
                }
            }
        }
        
    }
    //verificar os dinos vivos
    for(i=0;i<t_rexs.size();i++){
        T_REX *t = t_rexs.at(i);
        if(t->isDead()){
            T_REX *aux = t_rexs.at(t_rexs.size()-1);
            t_rexs.at(t_rexs.size()-1) = t_rexs.at(i);
            t_rexs.at(i) = aux;
        }
    }


*/