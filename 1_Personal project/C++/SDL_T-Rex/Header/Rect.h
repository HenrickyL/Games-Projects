#ifndef RECT_H
#define RECT_H
#include "../Header/Window.h"

class Rect : public Window{
public:
    Rect(const Window &window, double x, double y);
    Rect(const Window &window, int w, int h, double x, double y);
    Rect(const Window &window, int w, int h, double x, double y, int r, int g, int b, int a);
    void pollEvents();
    void draw() const;
    void color(std::string cor);
    void color(int r, int g, int b);
    void alpha(int a);
protected:
    int _w, _h;
    double _x, _y;
    int  _r = 0, _g = 0, _b = 255, _a = 255;


};


#endif