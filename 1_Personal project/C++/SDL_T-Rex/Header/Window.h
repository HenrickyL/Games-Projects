#ifndef WINDOW_H
#define WINDOW_H
//classe janela que vai configurar tudo na tela


#include <string>
#include "SDL2/SDL.h"
#include "SDL2/SDL_opengl.h"

class Window{
public:
    Window(const std::string &title, int width, int height);
    ~Window();
    //getter e setter
//Que estranha esse método
    void pollEvents(); // verificar eventos
    void clear() const; //

    inline bool isClosed() const {return _closed;}//getIsClossed
    void setClosed(bool closed);
    void color(std::string cor);
private:
    bool init(); // criar a janela
     
private: //atributos
    std::string _title = "Title"; //titulo
    SDL_Window *_window;
    bool _closed = false;
    int _R=0,_G=0,_B=0,_A=255;
   
    
protected:
    int _width = 800;
    int _height = 600; //dimensões
    SDL_Renderer *_renderer = NULL;

};

#endif