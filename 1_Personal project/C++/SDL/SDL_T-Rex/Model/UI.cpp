#include <iostream>
#include "../Header/variable.h"
#include "../Header/UI.h"


//////////////////////////////////
UILabel::UILabel(Window* window,int posX, int posY, std::string text, std::string font, std::string color)
: Window(*window),_labelFont(font), _labelText(text)
{
    _font = TTF_OpenFont(_fontPath.c_str(),_fontSize);
    _textColor = colors[color];
    _position.x = posX;
    _position.y = posY;
    setLabelText(text);
}
UILabel::UILabel(Window* window,int posX, int posY)
: Window(*window)
{  
    _font = TTF_OpenFont(_fontPath.c_str(),_fontSize);
    _position.x = posX;
    _position.y = posY;
    setLabelText("::Text::");
}

UILabel::~UILabel(){
    SDL_DestroyTexture(_labelTexture);
    TTF_CloseFont(_font);
    if(this != NULL){
        delete this;
    }
}
//////////////////////////////////
void UILabel::setLabelText(std::string text){

    SDL_Surface* surface = TTF_RenderText_Blended(_font,text.c_str(),_textColor);   
    if(surface == nullptr){
        std::cerr << "Error create Surface!\n";
    }
    _labelTexture = SDL_CreateTextureFromSurface(_renderer,surface);
    if(_labelTexture == nullptr){
        std::cerr << "Error create Texture!\n";
    }
    SDL_FreeSurface(surface);

    SDL_QueryTexture(_labelTexture, nullptr,nullptr,&_position.w,&_position.h);
    updateRect();
    
}
//renderizar
void UILabel::render(){
    if(_renderer != nullptr && _labelTexture != nullptr )
        SDL_RenderCopy(_renderer,_labelTexture,nullptr,&_position );
}
void UILabel::updateRect(){
    _position.x = _position.x - _position.w ;
    _position.y = _position.y - _position.h;
}
void UILabel::addFont(std::string path,int size){
     TTF_CloseFont(_font);
     _font = TTF_OpenFont(path.c_str(),size);
}
//////////////////////////////////
