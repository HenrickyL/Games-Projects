#ifndef WINDOW_H
#define WINDOW_H
//classe janela que vai configurar tudo na tela


#include <string>
#include "SDL2/SDL.h"
#include "SDL2/SDL_opengl.h"
#include "SDL2/SDL_ttf.h"

class Window{
public:
    Window(const std::string &title, int width, int height);
    ~Window();
    //getter e setter
//Que estranha esse método
    static int _ticks; //contar tick no geral
    bool _pause = false;
    void pollEvents(); // verificar eventos
    void clear(); //
    inline bool isClosed() const {return _closed;}//getIsClossed
    static void setClosed(bool closed);
    void color(std::string cor);
    void drawText(const char *text, int x, int y);
private:
    bool init(); // criar a janela
    void upgradeVar();
     
private: //atributos
    std::string _title = "Title"; //titulo
    SDL_Window *_window;
    static bool _closed;
    static int _time;
    int _R=0,_G=0,_B=0,_A=255;
    
protected:
    int _width = 800;
    int _height = 600; //dimensões
    SDL_Renderer *_renderer = NULL;
public:
    static SDL_Renderer *_rendererS;
    SDL_Renderer* getRenderer(){return _rendererS;}
    int getHeight()const{return _height;}
    int getWidth()const{return _width;}
    static int getTime(){return _time;}
};

#endif