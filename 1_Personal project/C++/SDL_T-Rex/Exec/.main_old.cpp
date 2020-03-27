#include <iostream>
#include <SDL/SDL.h>
#include "SDL/SDL_opengl.h"
#include "../model/variable.h"
#include "../model/T_rex.h"
#include "../model/Floor.h"


/*terminal:
	g++ -o main main.cpp ../model/Floor.cpp ../model/Entitie.cpp ../model/T_rex.cpp ../model/variable.h -lSDLmain -lSDL -lGL && ./main
*/

void sdlRequisitos(){
SDL_Init(SDL_INIT_EVERYTHING);
	//controle de memoria
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE,8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,8);
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE,32);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);
	//nome para a janela
	SDL_WM_SetCaption(Window,NULL);
	//size janela
	SDL_SetVideoMode(WIDTH,HEIGHT,32,SDL_OPENGL);
	//cor inicial
	glClearColor(1,1,1,1);//ultimo alpha
	glViewport(0,0,WIDTH,HEIGHT);
	//sombreamento
	glShadeModel(GL_SMOOTH);
	//2D
	glMatrixMode(GL_PROJECTION);//
	glLoadIdentity();//desenho geometrico
	//desabilitar 3D por enquanto
	glDisable(GL_DEPTH_TEST);
}



int main(int argc, char *argv[]){
	//requisitos do SDL
	sdlRequisitos();
	//Inicializar
	Floor chao =  Floor(0,100,WIDTH,HEIGHT);//WIDTH,HEIGHT,posX0,HEIGHT-posY0);
	T_REX dino = T_REX(WIDTH/2, HEIGHT/2, WIDTH,HEIGHT);
	//dino->start();

	
	///loop do jogo
	while(running){
		//eventos
		while(SDL_PollEvent(&events)){
			//fecha com x a janela
			if(events.type == SDL_QUIT){
				running = false;
			}/*if(events.type = SDL_KEYUP && events.key.keysym.sym == SDLK_ESCAPE){
				running = false;
			}*/
		}
		glClear(GL_COLOR_BUFFER_BIT);//LIMPARBUFFER
		//inicia a matriz de desenho
		glPushMatrix();
		//dimensões
		glOrtho(0,WIDTH,HEIGHT,0,-1,1);

////////////////////////////////////////////
		//Renderização
		chao.render();
		dino.render();
		
		//atualizações ticks
		//chao.tick();
		dino.tick();
///////////////////////////////////////////



		//Animação
	 	SDL_GL_SwapBuffers();
		ticks++;
	}
	//VVVVVV LOGICA VVVVVV




	






	std::cout<<"\nExecutando\n";
	//SDL_Delay(5000);
	SDL_Quit();
	//return EXIT_SUCCESS;
}