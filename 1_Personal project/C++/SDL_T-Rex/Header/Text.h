#ifndef TEXT_H
#define TEXT_H

#include "Window.h"

class Text : public Window{
public:
    Text(   Window &window, 
            int font_size,
            const std::string &messenge_text,
            const SDL_Color &color);
    Text(   const Window &window,
            const std::string &font_path, 
            int font_size,
            const std::string &messenge_text,
            const SDL_Color &color);
    //metodos
    void display(int x, int y);
    static SDL_Texture *loadFont(SDL_Renderer *renderer, const std::string &font_path, int font_size,const std::string &messenge_text,const SDL_Color &color);
    //getter e setter
    double getWidth(){return _text_rect.w;}
    double getHeight(){return _text_rect.h;}
private:
    std::string _font_path = "../Fonts/arial.ttf";
    SDL_Texture *_text_texture = NULL;
    SDL_Rect _text_rect;



};


#endif