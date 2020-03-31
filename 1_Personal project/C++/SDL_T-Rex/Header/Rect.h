#ifndef RECT_H
#define RECT_H
#include "../Header/Window.h"

class Rect : public Window{
public:
    Rect(const Window &window, double x, double y);
    Rect(const Window &window, double x, double y, int border);
    Rect(const Window &window, int w, int h, double x, double y);
    Rect(const Window &window, int w, int h, double x, double y, int r, int g, int b, int a);
    void pollEvents(); // verificar eventos
    void draw() const; // desenhar o retangulo na tela
    void color(std::string cor); // mudar cor usando string
    void color(int r, int g, int b); // mudar cor
    void alpha(int a); // mudar alpha da cor
    bool intersect(Rect B); // verificar contato de retangulos
    void set_X(double x){_x = x;}
    double get_X()const{return _x;}
protected:
    int _border=1;
    int _w, _h;
    double _x, _y;
    int  _r = 0, _g = 0, _b = 255, _a = 255;
    //getter e setter
};


#endif