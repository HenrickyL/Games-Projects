#include "Floor.h"
#include <SDL/SDL.h>
#include "SDL/SDL_opengl.h"


Floor::Floor(double x, double y, double w, double h): ENTITIE(x,y){
                    //valores devem ficar assim                      
    this->initX = w; // x0
    this->initY = h; // Height - y0
    this->x = x; // width
    this->y = y; // height
}
//Floor::~Floor(); por missão deve dar certo
void Floor::render(){
    glLineWidth(2);
    glBegin(GL_LINES);//GL_points,GL_LINEs, GL_LOOP, GL_QUADS,GL_Triangles,GL_Poligon
    glColor4ub(0,0,255,255);
    glVertex2f(initX,initY);
    glVertex2f(x,initY);
    glEnd();
}
