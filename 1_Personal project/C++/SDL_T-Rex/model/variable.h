#ifndef VAR_H
#define VAR_H

#include <vector>
#include "Entitie.h"
#include <SDL/SDL.h>
#include "SDL/SDL_opengl.h"

    std::vector<ENTITIE>    Entities;
    //Variáveis
	int 					width=200, height=600;
	int                     ticks=0;
	int                     x0=0,y0=30;		
	//loop
	bool                    running = true;
	//eventos teclado e mais
	SDL_Event               events;




#endif
