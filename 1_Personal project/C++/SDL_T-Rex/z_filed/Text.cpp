#include <iostream>
#include<sstream>
#include "../Header/Text.h"

Text::Text(Window *window,int size):
Window(*window),_size(size)
{
    _error = init();
    std::cerr << "Font Criada!";
    
}
Text::Text(Window *window,int size,char* font_path):
Window(*window),_size(size),_fontPath(font_path)
{   
    _error = init();
    std::cerr << "Font Criada!";
}
Text::~Text(){
    
    SDL_FreeSurface(_surface);
    SDL_DestroyTexture(_texture);
    TTF_CloseFont(_font);
    TTF_Quit();     // finalizando ttf
}

bool Text::init(){
    TTF_Init();     //inicializando TTF
    //carregando font
    _font = TTF_OpenFont(_fontPath.c_str(),_size);
    if(_font == nullptr){
        std::cerr << "Falha ao carregar Font!\n";
        return true;
    }
    return false;
}

bool Text::createSurface(){
    //desalocação
    SDL_FreeSurface(_surface); 
    SDL_DestroyTexture(_texture);
    // Criando Surface do texto                 
    _surface = TTF_RenderText_Solid(_font,_text.c_str(),_color);          // Criar novos
    if(_surface == nullptr){
        std::cerr << "Falha ao criar Surface!\n";
        return false;
    }
        // definindo retangulo
    _rect->w = _surface->w;
    _rect->h = _surface->h;
        // Criando Textura - > colocar texto na tela
    _texture = SDL_CreateTextureFromSurface(_renderer, _surface);
    if(_texture == NULL){
        std::cerr << "Failed to create Texture!\n";
        return false;
    }
    

    return true; // foi criado
}


void Text::drawText(char* text, int x, int y){
    if(_text != text){  
        _text = text;
        _rect->x = x;
        _rect->y = y;
        bool initSurface;
        initSurface = createSurface();          // crio uma surface
        if(initSurface){                        // Se consegui criar desenho na tela
            SDL_RenderCopy(_renderer, _texture, nullptr, _rect);
        }
    }
}

void Text::drawText(std::string &text, int x, int y){
    if(_text != text){  
        _text = text;
        _rect->x = x - _rect->w;
        _rect->y = y;
        bool initSurface;
        initSurface = createSurface();          // crio uma surface
        if(initSurface){                        // Se consegui criar desenho na tela
            SDL_RenderCopy(_renderer, _texture, nullptr, _rect);
        }
    }
}





//getter e setter
double Text::getWidth(){return _rect->w;}
double Text::getHeight(){return _rect->h;}
void Text::setText(char* text){_text = text;}
void Text::color(SDL_Color &color){_color = color;}