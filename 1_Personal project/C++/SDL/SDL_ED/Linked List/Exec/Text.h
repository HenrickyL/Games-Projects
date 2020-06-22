#ifndef TEXT_H
#define TEXT_H

#include "Window.h"

class Text : public Window{
public:
        Text(Window *window,int size);
        Text(Window *window,int size,char* font_path);
        ~Text();
        void Error(bool error);
        bool init(const char* text);
        void drawText(const char* text, int x, int y);
        void drawText(std::string &text, int x, int y);
        void drawText(int text, int x, int y);
private:
        bool _start = false;
        bool _error = false;
        SDL_Rect _rect;
        int _size = 24;
        std::string _font_path = "../Fonts/arial.ttf";
        std::string _text;
        SDL_Color _color = {255,0,0};
        //pointer
        TTF_Font *_font;
        SDL_Surface *_surface;
        SDL_Texture *_texture;
public://getter e setter
        double getWidth();
        double getHeight();
        void setColor(SDL_Color &color);
        void setText(char* text);
        
};


#endif