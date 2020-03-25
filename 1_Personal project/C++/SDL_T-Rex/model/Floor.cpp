#include "Floor.h"
#include <SDL/SDL.h>
#include "SDL/SDL_opengl.h"
#include "variable.h"

Floor::Floor(): ENTITIE(x0,height-y0){
    this->x = width;
    this->y = height;
}
//Floor::~Floor(); por missão deve dar certo
void Floor::render(){
    glLineWidth(2);
    glBegin(GL_LINES);//GL_points,GL_LINEs, GL_LOOP, GL_QUADS,GL_Triangles,GL_Poligon
    glColor4ub(0,0,255,255);
    glVertex2f(x0,height-y0);
    glVertex2f(width,height-y0);
    glEnd();
}
