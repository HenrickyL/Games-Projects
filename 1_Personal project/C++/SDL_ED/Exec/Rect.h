#ifndef RECT_H
#define RECT_H
#include "Window.h"


class Rect : public Window{
public:
    Rect(Window *window, int w, int h, double x, double y, int r, int g, int b, int a);
    Rect(Window *window, double x, double y);
    Rect(Window *window, double x, double y, int border);
    Rect(Window *window, int w, int h, double x, double y);
    Rect(SDL_Renderer *render, int w, int h, double x, double y);
    void keyEvents(); // verificar eventos
    void draw() const; // desenhar o retangulo na tela
    void color(std::string cor); // mudar cor usando string
    void color(int r, int g, int b); // mudar cor

    void alpha(int a); // mudar alpha da cor
    bool intersect(Rect *B); // verificar contato de retangulos
    void setX(double x){_x = x;}
    double getX()const{return _x;}
    double getY()const{return _y;}
    std::string getType(){return _type;}
    void setType(std::string type){_type = type;}
protected:
    std::string _type = "rect";
    int _border=1;
    int _w, _h;
    double _vx=0.2,_vy=0.2;
    double _x, _y;
    Window *_window;
    int  _r = 0, _g = 0, _b = 255, _a = 255;
    
public:
    //getter e setter
    SDL_Color getColor();
    std::string getColorStr();

};


#endif