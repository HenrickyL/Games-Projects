#include <iostream>
#include<sstream>
#include "Text.h"

Text::Text(Window *window,int size):
Window(*window),_size(size)
{
    _error = init("");
    _start = true;
}
Text::Text(Window *window,int size,char* font_path):
Window(*window),_size(size),_font_path(font_path)
{
    _error = init("");
    _start = true;
}
Text::~Text(){
    SDL_FreeSurface(_surface);
    SDL_DestroyTexture(_texture);
}
//inicializador
bool Text::init(const char* text){
    if(!_start){
        _font = TTF_OpenFont(_font_path.c_str(), _size);
        if(_font == NULL){
            std::cerr << "Failed to load Font!\n";
            return true;
        }
    }
    if(text != _text && !_error){
        _text = text;
        _surface = TTF_RenderText_Blended(_font, text, _color);
        if(_surface == NULL){
            std::cerr << "Failed to create Serface!\n";
            return true;
        }
        _texture = SDL_CreateTextureFromSurface(_renderer, _surface);
        if(_texture == NULL){
            std::cerr << "Failed to create Texture!\n";
            return true;
        }
        _rect.w = _surface->w;
        _rect.h = _surface->h;

    }
    return false;
}
void Text::Error(bool error){
    if(_error){
        _text = "error";
        std::cout << "Text::error\n";
    }

}

void Text::drawText(const char* text, int x, int y){
    _error = init("text");
    _rect.x = x;
    _rect.y = y;
    SDL_RenderCopy(_renderer, _texture, nullptr, &_rect);
    
}
void Text::drawText(std::string &text, int x, int y){
    _error = init(text.c_str());
    _rect.x = x;
    _rect.y = y;
    SDL_RenderCopy(_renderer, _texture, nullptr, &_rect);
    /*_text = text;
    TTF_Font* font = TTF_OpenFont(_font_path.c_str(), _size);
    if(font == NULL){
        std::cerr << "Failed to load Font!\n";
    }
    SDL_Surface* surface = TTF_RenderText_Blended(font, _text.c_str(), _color);
    if(surface == NULL){
        std::cerr << "Failed to create Serface!\n";
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(_renderer, surface);
    if(texture == NULL){
        std::cerr << "Failed to create Texture!\n";
    }
    _rect = {x, y, surface->w, surface->h};
    SDL_FreeSurface(surface);
    SDL_RenderCopy(_renderer, texture, nullptr, &_rect);
    SDL_DestroyTexture(texture);
    */
}
/*void Text::drawText(int text, int x, int y){
    std::string str = "";
	str += std::to_string(text);
    //char* a = str.c_str();

    drawText(str,x,y);
}*/
//getter e setter
double Text::getWidth(){return _rect.w;}
double Text::getHeight(){return _rect.h;}
void Text::setText(char* text){_text = text;}
void Text::setColor(SDL_Color &color){_color = color;}