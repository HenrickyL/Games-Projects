#include<iostream>
#include "../Header/Text.h"
//construtor
Text::Text(){

}
//destrutor
Text::~Text(){    
    if(this != NULL){
        delete this;
    }
}
///////////////////////////////////////////////////////////////////////////////////////
//adicionar uma font
void Text::addFont(std::string id, std::string path, int fontSize){
    fonts.emplace(id,TTF_OpenFont(path.c_str(),fontSize)); //add global
    _fonts.emplace(id,TTF_OpenFont(path.c_str(),fontSize));
}
//adcionar uma font
void Text::addFont(int fontSize){
    //add font
    fonts.emplace(_fontId.c_str(),TTF_OpenFont(_fontPath.c_str(),fontSize));//add global
    _fonts.emplace(_fontId.c_str(),TTF_OpenFont(_fontPath.c_str(),fontSize));

}
    




////////////////////////////////////////////////////////////////////////////////////////
TTF_Font* Text::getFont(std::string id){
    return _fonts[id];
}