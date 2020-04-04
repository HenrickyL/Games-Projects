//arquivo de "Interface"
#ifndef ENTITIE_H
#define ENTITIE_H

#include "Window.h"
#include "Rect.h"
//todo tipo de entidade, como Chão, Nuvem, TRex, Obstaculo

class Entitie : public Rect {
protected:
	int _initTime = Window::getTime();
	//atributos
	
	//sprite
	//int frameCurrent;//frame atual

	

public:
	//Entitie(const Window &window);
	Entitie(Window *window , double x, double y);
	Entitie(Window *window , int w, int h, double x, double y); //Construtor Dinosauro
	//~Entitie();//Destrutor
	
	//Métodos
	void tick();
	void render();
	
	//getter e setter
	double getX();
	void setX(double x);
	double getY();
	void setY(double y);


};


#endif