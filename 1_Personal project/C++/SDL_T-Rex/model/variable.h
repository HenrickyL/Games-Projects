#ifndef VAR_H
#define VAR_H
#include <iostream>
#include <SDL/SDL.h>
#include "SDL/SDL_opengl.h"
#include <vector>
#include "Entitie.h"
#include <string>


std::vector<ENTITIE>    Entities;
//Variáveis
char                  Window[] = "T_REX";
int 					WIDTH = 600;
int						HEIGHT = 400;
int                     ticks = 0;
int 	                posX0 = 0;
int						posY0 = 50;		
//loop
bool                    running = true;
//eventos teclado e mais
SDL_Event               events;




#endif
