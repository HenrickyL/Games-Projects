#include <iostream>
#include <SDL/SDL.h>
#include "SDL/SDL_opengl.h"
/*terminal:
	g++ -o main main.cpp -lSDLmain -lSDL -lGL
*/


//#include "SDL_opengl.h"
int main(int argc, char *argv[]){
	/*if(SDL_Init(SDL_INIT_EVERYTHING)<0){
		std::cout << "SDL not inicializad, error: "<<SDL_GetError()<<std::endl;	
	}*/
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
	SDL_WM_SetCaption("MEu primeiro jogo SDL",NULL);
	//size janela
	SDL_SetVideoMode(600,400,32,SDL_OPENGL);
	//cor inicial
	glClearColor(1,1,1,1);//ultimo alpha
	//area exibida
	glViewport(0,0,600,400);
	//sombreamento
	glShadeModel(GL_SMOOTH);
	//2D
	glMatrixMode(GL_PROJECTION);//
	glLoadIdentity();//desenho geometrico
	//desabilitar 3D por enquanto
	glDisable(GL_DEPTH_TEST);

	//VVVVVV LOGICA VVVVVV




	//Renderização
	glClear(GL_COLOR_BUFFER_BIT);//LIMPARBUFFER
	//Animação
	 SDL_GL_SwapBuffers();






	std::cout<<"\nExecutando\n";
	SDL_Delay(5000);
	SDL_Quit();
	//return EXIT_SUCCESS;
}