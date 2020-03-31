#include <iostream>
#include "../Header/Text.h"


//construtor
Text::Text( Window &window,
            int font_size,
            const std::string &messenge_text,
            const SDL_Color &color):
Window(window)
{
    _text_texture = loadFont(_renderer,_font_path,font_size,messenge_text,color);
    SDL_QueryTexture(_text_texture,NULL,NULL,&_text_rect.w,&_text_rect.h);
}
Text::Text( const Window &window,
            const std::string &font_path, 
            int font_size,
            const std::string &messenge_text,
            const SDL_Color &color):
Window(window),_font_path(_font_path)
{
    _text_texture = loadFont(_renderer,_font_path,font_size,messenge_text,color);
    SDL_QueryTexture(_text_texture,NULL,NULL,&_text_rect.w,&_text_rect.h);
}

//display
void Text::display(int x, int y){
    _text_rect.x = x;
    _text_rect.y = y;
    SDL_RenderCopy(_renderer, _text_texture,NULL,&_text_rect);
}
//
SDL_Texture *Text::loadFont(SDL_Renderer *renderer,const std::string &font_path, int font_size,const std::string &messenge_text,const SDL_Color &color){
    TTF_Font *font = TTF_OpenFont(font_path.c_str(),font_size);    
    if(!font){
        std::cerr << "Falha em carregar a Fonte!\n";
    }
    auto text_surface = TTF_RenderText_Solid(font,messenge_text.c_str(),color);
    if(!text_surface){
        std::cerr << "Failed to create Text_surface!\n";
    }
    auto text_texture = SDL_CreateTextureFromSurface(renderer,text_surface);
    if(!text_texture){
         std::cerr << "Failed to create Text_texture!\n";
    }
    SDL_FreeSurface(text_surface);
    return text_texture;
}
