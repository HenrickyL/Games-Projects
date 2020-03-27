#include <iostream>
#include "../Header/Window.h"
//que notação legal

Window::Window(const std::string &title, int width, int height) :
_title(title), _width(width), _height(height)
{   
    _closed = !init();
}
Window::~Window(){
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

bool Window::init(){
    if(SDL_Init(SDL_INIT_EVERYTHING) !=0 ){
        std::cout<<"Falha ao inicializar SDL.\n";
        return 0;
    }//sucesso
    //crio a "janela"
    _window = SDL_CreateWindow(
        _title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        _width,_height,
        0//SDL_WINDOW_RESIZABLE
    );
    //verificar se foi criado com sucesso
    if(_window == NULL){
        std::cerr << "Falha em criar a Janela!\n";
        return 0;
    }
    //criar um "render"
    _renderer = SDL_CreateRenderer(_window,-1,SDL_RENDERER_ACCELERATED);
    //verificar
    if(_renderer == NULL){
        std::cerr << "Falha em criar o Renderizador!\n";
        return 0;
    }
    return true;
}
void Window::setClosed(bool closed){
    _closed = closed;
}
void Window::pollEvents(){
    //crio um evento
    SDL_Event event;
    if(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT)  _closed = true;
    }

}

void Window::clear() const{
    SDL_RenderPresent(_renderer);
    SDL_SetRenderDrawColor(_renderer,_R,_G,_B,_A);
    SDL_RenderClear(_renderer);
    
}

void Window::color(std::string cor){
    
    if(cor == "blue"){
        _R=0,_G=0,_B=255;
    }else if(cor == "red"){
        _R=255,_G=0,_B=0;
    }else if(cor == "white"){
        _R=255,_G=255,_B=255;
    }else if(cor == "yellow"){
        _R=255,_G=255,_B=0;
    }else if(cor == "green"){
        _R=0,_G=255,_B=0;
    }else{
        
    }
}