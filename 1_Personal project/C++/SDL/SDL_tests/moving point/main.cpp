#include <iostream>
#include <SDL/SDL.h>
#include "SDL/SDL_opengl.h"
#include <math.h>
/*terminal:
	g++ -o main main.cpp -lSDLmain -lSDL -lGL && ./main
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
	int width=600, heigth=400;
	//nome para a janela
	SDL_WM_SetCaption("MEu primeiro jogo SDL",NULL);
	//size janela
	SDL_SetVideoMode(width,heigth,32,SDL_OPENGL);
	//cor inicial
	glClearColor(1,1,1,1);//ultimo alpha
	//Area exibida
	
	glViewport(0,0,width,heigth);
	//sombreamento
	glShadeModel(GL_SMOOTH);
	//2D
	glMatrixMode(GL_PROJECTION);//
	glLoadIdentity();//desenho geometrico
	//desabilitar 3D por enquanto
	glDisable(GL_DEPTH_TEST);
	//Variáveis
		//math teste
		int ticks=0,theta = 0;
		int x=width/2,y=heigth/2,r=100;
		
		//loop
	bool running = true;
		//eventos teclado e mais
	SDL_Event events;
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
		//Renderização
		glClear(GL_COLOR_BUFFER_BIT);//LIMPARBUFFER
		//inicia a matriz de desenho
		glPushMatrix();
		//dimensões
		glOrtho(0,width,heigth,0,-1,1);
		//cor glColor3d(1 ou 0) ou glColor3f(decimais) ou glColor3ub(rgb)[0-255] ou glColor4ub(R,G,B,A)
		
		//inicio desenho
		if(events.type == SDL_KEYDOWN && events.key.keysym.sym == SDLK_LEFT){
			x-=5;
		}
		else if(events.type == SDL_KEYDOWN && events.key.keysym.sym == SDLK_RIGHT){
			x+=5;
		}

		glPointSize(30);
		glBegin(GL_POINTS);
			glColor4ub(0,0,255,255);
			glVertex2i(x,y);
			
		glEnd();
		
		
		
		//fecha a matriz
		glPopMatrix();

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