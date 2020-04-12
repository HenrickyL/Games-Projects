#ifndef TEXT_H
#define TEXT_H

#include "Window.h"
/*
        * Biblioteca que gerencia um texto com um tamanho e fonte



*/




class Text : public Window{
public:
        Text(Window *window,int size);
        Text(Window *window,int size,char* font_path);
        ~Text();
        void Error(bool error);
        bool init();                                                    // Função inicializadora (inicia font e size)
        void drawText(char* text, int x, int y);
        void drawText(std::string &text, int x, int y);
        void drawText(int text, int x, int y);
private:                 
        bool _error = false;                                            // indica que houve algum erro
        SDL_Rect *_rect;                                                // Retangulo do texto
        int _size = 24;                                                 // Tamanho do texto
        std::string _fontPath = "../Fonts/arial.ttf";                   // Localização da font
        std::string _text = "::Text::";                                              // Texto a ser "desenhado"
        SDL_Color _color = {255,0,0};                                   // Cor do texto
        //pointer
        TTF_Font *_font;                                                // Ponteiro da Font criada
        SDL_Surface *_surface;                                          // Ponteiro da Surface( Texto )
        SDL_Texture *_texture;                                          // Ponteiro da Textura

        //Métodos
        bool createSurface();

public://getter e setter
        double getWidth();
        double getHeight();
        void color(SDL_Color &color);
        void setText(char* text);
        
};


#endif