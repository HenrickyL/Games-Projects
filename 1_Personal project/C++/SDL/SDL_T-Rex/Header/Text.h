/* Header File - Text controlls
    - HenrickyL1@gmail.com
    - font: https://youtu.be/PHaP3wDggnw
*/

#ifndef TEXT_H
#define TEXT_H
#include<iostream>
#include<map>
#include"variable.h"
#include "Window.h"

class Text{
public:
    Text();
    ~Text();
private:
    std::map<std::string,TTF_Font*>_fonts;
    std::string _fontId = "arial";
    std::string _fontPath = "../Fonts/arial.ttf";
    int _fontSize = 25;
    SDL_Color _fontcolor = {255,0,0}; 
public: //metodos auxiliareas
    void addFont(std::string id, std::string path, int fontSize);
    void addFont(int fontSize);
    
public: //getter e setter
    TTF_Font* getFont(std::string id);

};


#endif