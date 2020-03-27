#include "../Header/Floor.h"
#include <SDL/SDL.h>
#include "SDL/SDL_opengl.h"


Floor::Floor(double x, double y, double w, double h): ENTITIE(x,y,w,h){
                    //valores devem ficar assim                      
    this->initX = 0;
    this->initY = 0;
}
//Floor::~Floor(); por missão deve dar certo
void Floor::render(){
    glOrtho(0,this->initX,this->initY,0,-1,1);
    glLineWidth(3);
    glBegin(GL_LINES);//GL_points,GL_LINEs, GL_LOOP, GL_QUADS,GL_Triangles,GL_Poligon
    glColor4ub(0,0,255,0);
    glVertex2f(initX,height-y); //ponto no começo
    glVertex2f(width,height-y); // ponto no dim
    glEnd();
}
